/*
      Title: Highly divisible triangular number
      Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler012/problem
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e6+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

bool isPrime[N];
vector<ll>primes;

void PrimeGen(ll n){
    for(int i=3; i<=n; i+=2) isPrime[i] = 1;

    ll sqr = sqrt(n);
    for(int i=3; i<=sqr; i+=2){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = 0;
            }
        }
    }

    isPrime[2] = 1;
    primes.push_back(2);

    for(int i=3; i<=n; i+=2){
        if(isPrime[i]==1) primes.push_back(i);
    }
}

ll NOD(ll n){
    ll nod = 1;
    for(auto p: primes){
        if(p*p>n) break;
        if(n%p==0){
            ll cnt = 0;
            while(n%p==0){
                n/=p;
                cnt++;
            }
            cnt++;
            nod *= cnt;
        }
    }
    if(n>1) nod*=2;
    return nod;
}

int main(){
    FASTER

    ll lim = 1e6;
    PrimeGen(lim);

    ll t;
    cin>>t;
    while(t--){
        ll need;
        cin >> need;
        ll n = 1;
        while(true){
            ll a,b;
            if(n%2==0){
                a = n/2;
                b = n+1;
            } else {
                a = n;
                b = (n+1)/2;
            }

            ll d = NOD(a)*NOD(b);
            if(d>need){
                cout<<n*(n+1)/2<<nl;
                break;
            }
            n++;
        }
    }
}







/* Intuition:
    This is a key optimization:
        Triangular number: T_n = n*(n+1)/2.
        T_n = (n*(n+1))/2 = (n/2)*(n+1) if n is even, (n)*((n+1)/2) if n is odd.
        Divisor count is multiplicative for coprime numbers:

    NOD(T_n) = NOD(a) * NOD(b) where gcd(a, b) = 1.
    This avoids factoring T_n directly, making it faster.
*/
