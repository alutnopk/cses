#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC target ("arch=sandybridge")
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

#define NMAX 1000

int dp[NMAX+1][NMAX+1];

int tform(char ch)
{
    if(ch == '*') return 1;
    else return 0;
}

int solve(const vector<vector<int>>& grid, int m, int n)
{
    // // lookup
    // if(dp[m][n] != -1) return dp[m][n];
    // // base case
    // if(m==1 && n==1)
    // {
    //     dp[m][n] = 1-tform(grid[m][n]);
    //     return dp[m][n];
    // }
    // else if(m==1)
    // {
    //     for(int i0=1; i0<=n; i0++)
    //         if(grid[m-1][i0-1] == 1)
    //         {
    //             dp[m][n] = 0; return dp[m][n];
    //         }
    //     dp[m][n] = 1; return dp[m][n];
    // }
    // else if(n==1)
    // {
    //     for(int i0=1; i0<=m; i0++)
    //         if(grid[i0-1][n-1] == 1)
    //         {
    //             dp[m][n] = 0; return dp[m][n];
    //         }
    //     dp[m][n] = 1; return dp[m][n];
    // }
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 1; dp[0][i] = 1;
    }
    for(int i=1; i<=n; i++)
    {
        if(grid[i][1]) dp[i][1] = 0;
        else
        {
            dp[i][1] = dp[i-1][1];
        }
        if(grid[1][i]) dp[1][i] = 0;
        else
        {
            dp[1][i] = dp[1][i-1];
        }
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=n; j++)
        {
            if(grid[i][j]) dp[i][j] = 0;
            else
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % p7;
            }
        }
    }
    // recursion
    return dp[m][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<vector<int>> grid(n+1, vector<int>(n+1));
    string sin;
    for(int i=1; i<=n; i++)
    {
        cin >> sin;
        transform(sin.begin(), sin.end(), grid[i].begin()+1, tform);
    }
    for(int i=0; i<=NMAX; i++)
        for(int j=0; j<=NMAX; j++)
            dp[i][j] = -1;

    cout<<solve(grid, n, n)<<endl;
    return 0;
}