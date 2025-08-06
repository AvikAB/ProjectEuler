/*
# Title: 10001st prime
Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler007

Intuition: N is given, Print the Nth Prime number. Use PrimeGen() for precalculate the prime numbers and print the N-1 (0-indexed) prime number.

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

const ll N = 1e7+1234;
const ll mod = 1e9+7;

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

int main(){
    FASTER;

    ll lim = 1e6;
    PrimeGen(lim);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<primes[n-1]<<nl;
    }
}
