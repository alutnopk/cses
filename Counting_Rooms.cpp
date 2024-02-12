#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int cc=0, m=0, n=0;
int grid[1000][1000], vis[1000][1000];
void dfs(int p, int q)
{
    // p,q must be unvisited
    vis[p][q] = 1;
    if(p>0 && grid[p-1][q] && !vis[p-1][q])
        dfs(p-1, q);
    if(p<n-1 && grid[p+1][q] && !vis[p+1][q])
        dfs(p+1, q);
    if(q>0 && grid[p][q-1] && !vis[p][q-1])
        dfs(p, q-1);
    if(q<m-1 && grid[p][q+1] && !vis[p][q+1])
        dfs(p, q+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    // vector<vector<int>> grid(n, vector<int>(m)), vis(n, vector<int>(m, 0));
    memset(vis, 0, sizeof(vis));
    // bzero(vis, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        for(int j=0; j<m; j++)
        {
            grid[i][j] = (s[j]=='.')? 1: 0;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] && !vis[i][j])
            {
                cc++;
                dfs(i, j);
            }
        }
    }
    cout<<cc<<endl;
    return 0;
}