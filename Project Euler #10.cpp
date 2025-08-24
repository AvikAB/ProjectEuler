/*
Title: Summation of primes
Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler010/problem

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
    FASTER

    ll lim = 1e6;
    PrimeGen(lim);
    vector<ll>pre(lim+1, 0);
    ll sum = 0;
    for(auto p:primes){
        sum += p;
        pre[p] = sum;   // sum assign at prime position
    }

    // fill gaps for all non-primes to their previous primes sum
    for(int i=1; i<=lim; i++){
        if(pre[i]==0) pre[i] = pre[i-1];
    }

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<pre[n]<<nl;
    }
}
