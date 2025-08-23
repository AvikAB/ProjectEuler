/*

Title: Largest product in a series
Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler008/problem


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
    FASTER

    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        string num;
        cin>>n>>m>>num;
        ll best = 0;
        for(int i=0; i+m<n; i++){   // loop ends when there are less than m digits left
            ll curr = 1;
            for(int j=0; j<m; j++){  // convert str to int
                curr *= num[i+j]-'0';
            }
            if(best<curr) best = curr;  // checking
        }
        cout<<best<<nl;
    }
}













/*
Intuition: Go with the first index (i) and inner loop (j) is like a window. If j=0 then it will work with num[i+0](where i is present now), j=1 it will be num[i+1],....num[i+4] and complete the window. Convert its ascii to int and then checking that curr is greater then best, if its then best = curr. JUst bruteforce approach. T.C -> O(t*10^3) = O(10^5)
*/
