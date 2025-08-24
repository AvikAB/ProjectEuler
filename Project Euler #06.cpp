/*
# Title: Sum square difference
Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler006

Intuition: Just the absolute difference between the sum of the squares of the first N natural numbers and the square of the sum.
          Just use the formula.
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
        ll SqSum = (n*(n+1)*(2*n+1))/6;
        ll SumSq = ((n*(n+1))/2)*((n*(n+1))/2);
        cout<<abs(SqSum-SumSq)<<nl;
    }
}
