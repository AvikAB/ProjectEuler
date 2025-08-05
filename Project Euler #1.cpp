/*
# Title: Multiples of 3 and 5
link: https://www.hackerrank.com/contests/projecteuler/challenges/euler001/

Intuition:
. Sum of all numbers from 1 to n which is divisible by x = x*(k(k+1)/2); where k = floor(n/x) is the numbers of terms divisible by x from 1 to n.
Here, k*(k+1)/2 is the formula of sum of 1 to n.
The sum of all numbers divisible by 3 is : 3 * sum(x/3).
The sum of all numbers divisible by 5 is : 5 * sum(x/5).
here, we will count some number which is divisible by both(3 and 5) twice. 3*5 = 15 is divisible by both so that we should minus 15 * sum(x/15) from the total.
In the end, we print: 3 * sum(x/3) + 5 * sum(x/5) - 15 * sum(x/15).

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

ll sum(ll x){
    return (x*(x+1))/2;
}

int main(){
    FASTER;

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        n--;
        ll sumThree = 3* sum(n/3);   // (x/3) means nums betwn 1 to x are div by 3
        ll sumFive = 5* sum(n/5);   // the sum of all nums divisible by 5
        // Those num div by 5 & 3 count twice
        ll sumFifteen = 15* sum(n/15);

        cout<<(sumThree+sumFive-sumFifteen)<<nl;
    }
}
