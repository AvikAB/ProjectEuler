/*
    Title:  Large sum
    Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler013/problem

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

int main(){
    FASTER

    ll n;
    cin>>n;
    vector<ll>sum(60, 0);
    while(n--){
        string s;
        cin>>s;
        // add num to sum, for least significant digit
        ll carry = 0;
        ll len = s.size();
        for(int i=0; i<len; i++){
            ll dig = s[len-1-i] - '0';
            ll temp = sum[i]+dig+carry;
            sum[i] = temp%10;   // last dig of temp in the sum
            carry = temp/10;    // first dig of temp is the carry
        }
        // handle remaining carry
        ll idx = len;
        while(carry){
            ll temp = sum[idx]+carry;
            sum[idx] = temp%10;   // remaining carry will be add in the last idx in the sum
            carry = temp/10;
            idx++;
        }
    }
    // find highest non-zero dig
    ll highest = sum.size()-1;
    while(highest>=0 and sum[highest]==0){
        highest--;
    }
    // print first 10 digits:
    for(int i=highest; i>=max(highest-9LL, 0LL); i--){
        cout<<sum[i];
    }
    cout<<nl;
}







/* Intuition: n -> each n lines has 50 digits, sum it and print the 1st 10 digits of sum.

        Let, n = 3
        idx -> 0 1 2
               1 2 3            here, 1 is the most significant digit (MSD), 3 is the LSD.
               4 5 6
               7 8 9
    Start from reverse, dig = s[len-1-i]
    Each positions has digits, store each num digit by digit in a vector. For each num, add its digits to the corresponding
    positions in the sum. Keep track of carry when digit >9. Add carry in the next sum[i].
    If carry remains after adding al;l digits, propagate keep to the higher positions. Find the highest
    non-zero digit in the sum.
    Loop over digit from least Significant:
        For 1st str: 321
            dig      sum[i]    sum[i] after     carry
            3    ->    3    ->     3        ->    0
            2    ->    2    ->     2        ->    0
            1    ->    1    ->     1        ->    0
        sum: [3,2,1,0,...] 
        For 2nd str: 654
            dig      sum[i]    sum[i] after    carry
            6    ->  3+6=9 ->      9       ->    0
            5    ->  2+5=7 ->      7       ->    0
            4    ->  1+4=5 ->      5       ->    0
        sum: [9,7,5,0,...]
        For 1st str: 987
            dig      sum[i]        sum[i] after     carry
            9    ->  9+9=18      ->      8      ->    1
            8    ->  7+8+1(c)=16 ->      6      ->    1
            7    ->  5+7+1(c)=13 ->      3      ->    1 (rem carry)
    Remaining carry = 1 -> will place in sum[3] = 1
    sum: [8,6,3,1,0]
    Now, the last non-zero digit is at idx 3 (sum[3]=1). That means the num has 4 digits & print digits from idx-3.
*/
