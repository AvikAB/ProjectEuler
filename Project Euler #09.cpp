/*
Title:  Special Pythagorean triplet
Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler009/problem

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

    const int mxPeri = 3000;
    vector<ll> pre(mxPeri+1, -1);
    for(int a=1; a<mxPeri; a++){
        for(int b=a+1; b<mxPeri-a; b++){  // a<b
            // find c
            ll c2 = a*a + b*b;
            ll c = sqrt(c2);
            if(c*c != c2) continue;   // checking the correct sqr root or perfect sqr
            // check summing condition
            ll sum = a+b+c;
            if(sum>mxPeri) break;

            // pre-comp of pre
            if(pre[sum]<a*b*c) pre[sum] = a*b*c;
        }
    }

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<pre[n]<<nl;
    }
}













/*
Intuition:  a^2 + b^2 = c^2
           => c = sqrt(a^2+b^2)
        Its necessary to have a pre-computation of all perimeters.
        pre-compute all pairs a<b<c where a+b+c<=3000 because the limit in question is 3000.
        Find the a,b,c and multiply them and store in pre array where pre[a+b+c] = a*b*c.
        n will be given just print out the pre[n], it means we got a triplet sum where (a+b+c)
        stores the value of a*b*c.
*/
