/*
# Title: Even Fibonacci numbers
Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler002

Intuition: Just find the next fibonacci number, if the next fibo number is even then sum of it and print it.

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

int main(){
    FASTER;

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sum = 0;
        ll a = 1, b = 2;
        while(b<=n){
            if(b%2==0) sum += b;
            // next fibo
            ll nxt = a+b;
            a = b;
            b = nxt;
        }
        cout<<sum<<nl;
    }
}
