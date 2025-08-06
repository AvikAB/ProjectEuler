/*
# Title: Smallest Multiple
Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler005

Intuition: N is given, find the smallest number which is evenly divisible by all of numbers from 1 to N.

Example: Let, N = 10, Now we find the smallest num which is divisible by 1 to N.
                        1  2  3    4   5    6    7     8      9     10
  Prime factorization:  1  2  3  (2*2) 5  (2*3)  7  (2*2*2) (3*3) (2*5)
The method is to list each integer’s prime factors and retain the highest exponent of each prime across 1–10.
For 1–10, the maximum prime powers are 2³, 3², 5, and 7, whose product equals 2520. And 2520 is the number which is fully divisible by 1 to 10.

Basically, we have to find the LCM 1,2,3,....N.
LCM of (2 to N) -> Gives smallest positive number that is evenly divisible (divisible with no remainders) by all of the numbers from 1 to N.

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
        ll res = 1;
        for(int i=2; i<=n; i++){
            res = lcm(res, i);
        }
        cout<<res<<nl;
    }
}
