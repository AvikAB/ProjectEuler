/*
  Problem: Lattice Paths
  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler015/problem?

*/

// DFS to understand the traversal:

ll dfs(ll r, ll c, ll n, ll m){
    if(r==n and c==m) return 1;  // reached to the target, then cnt the way
    if(r>n or c>m) return 0;  // OFB
    ll down = dfs(r, c+1, n, m);
    ll right = dfs(r+1, c, n, m);

    return (down+right)%mod;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    cout<<dfs(0,0,n,m)<<nl;
}

// gives TLE, TC: O(2^n+m).

// Accepted DP code:
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

ll dp[501][501];

ll dfs(ll r, ll c, ll n, ll m){
    if(r==n and c==m) return 1;  // reached to the target, then cnt the way
    if(r>n or c>m) return 0;  // OFB
    if(dp[r][c]!=-1) return dp[r][c];
    ll down = dfs(r, c+1, n, m);
    ll right = dfs(r+1, c, n, m);

    return dp[r][c] = (down+right)%mod;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    memset(dp, -1, sizeof(dp));
    cout<<dfs(0,0,n,m)<<nl;
}

int main(){
    FASTER
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}

// TC: O(nm), SC: O(nm).

/*
n*m grid will be given. How many routes are present from top left corner to bottom right corner.

Intuition: There is total 2 ways to traverse for the minimum distance:
              1. n-1 moves down (vertical)
              2. m-1 moves right (horizontal)
          Total shortest paths = (n-1) + (m-1) = n+m-2 moves.
      ** 0-based or 1-based the minimum number of moves is always (n-1) + (m-1).

      ** Combination formula to solve this:  (easy way to avoid TLE)
              (width+height)! / width! * height!   [use this in code because of it gives the grid of squares, n-1 & m-1 gives the grids of points]
          => (n+m-2) / (n-1)! * (m-1)!
          The formula is written by (n+m-2) C (n-1).
  
  Another way is DFS / BFS traversal:
  Each grids consists of (width+1)*(height+1) points. Our co-ords will be [0][0] in the top left corner to [width-1][height-1] in the bottom right corner.

  The num of routes will be sum of all routes when going right plus all routes when going down: grid[r][c] = grid[r+1][c] + grid[r][c+1].
  Using to dp to avoid TLE.
*/
