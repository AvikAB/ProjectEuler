/*
    Title: Longest Collatz sequence
    Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler014/problem
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5000000;
vector<int> cache(N+1, -1);
vector<int> best(N+1, 1);

ll collatzLen(ll n) {
    if(n == 1) return 1;
    if(n <= N && cache[n] != -1) return cache[n];
    ll next = (n%2==0 ? n/2 : 3*n+1);
    ll res = 1 + collatzLen(next);
    if(n<=N) cache[n] = res;
    return res;
}

int main() {
    FASTER

    cache[1] = 1;
    ll mxLen = 1, bestN = 1;
    for(int i=2; i<=N; i++){
        int len = collatzLen(i);
        if(len >= mxLen){
            mxLen = len;
            bestN = i;
        }
        best[i] = bestN; // store best number so far
    }

    ll t;
    cin >> t;
    while(t--){
        ll x;
        cin>>x;
        cout<<best[x]<<nl;
    }
}





























/* Intuition: X is given, found a num which is <=X and given the longest chain.
              Using recursion with memoization. Collatz chain overlap thats why I use memo.
              store "best num so far" at each index.
*/
