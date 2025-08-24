/*

Title: Largest product in a grid
Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler011/problem

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

int main(){
    FASTER

    ll grid[20][20];
    // Input: read column-wise then row-wise (as you described)
    for(int col=0; col<20; col++){
        for(int row=0; row<20; row++){
            cin >> grid[row][col];
        }
    }

    ll best = 0;
    // walk through all cells of the grid
    for(int row=0; row<20; row++){
        for(int col=0; col<20; col++){

            // three more horizontal cell (to the right)
            if(col+3<20){
                ll curr = grid[row][col] * grid[row][col+1] * grid[row][col+2] * grid[row][col+3];
                best = max(best, curr);
            }

            // three more vertical cell (downward)
            if(row+3<20){
                ll curr = grid[row][col] * grid[row+1][col] * grid[row+2][col] * grid[row+3][col];
                best = max(best, curr);
            }

            // three more diagonal cell (down-right)
            if(row+3<20 and col+3<20){
                ll curr = grid[row][col] * grid[row+1][col+1] * grid[row+2][col+2] * grid[row+3][col+3];
                best = max(best, curr);
            }

            // three more diagonal cell (down-left)
            if(row+3<20 and col-3>=0){
                ll curr = grid[row][col] * grid[row+1][col-1] * grid[row+2][col-2] * grid[row+3][col-3];
                best = max(best, curr);
            }
        }
    }
    cout<<best<<nl;
}












/* Intuition: For each position of the grid I find the product of 4 connected cells:
    1. current cell and its three neighbors when going to the right side
    2. current cell and its three neighbors below it
    3. current cell and its three neighbors going right and down
    4. current cell and its three neighbors going left and down 
    For each of these steps I have to check whether enough neighbor exist.
    And finally the greatest product is printed.
*/
