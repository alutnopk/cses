#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

ll n;
vector<vector<int>> Tr;
vector<ll> sz, dist;

void dfs1(int u, int p) // calculate sum of paths for node 1
{
    sz[u] = 1LL; dist[u] = 0LL;
    for(int v: Tr[u])
    {
        if(v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dist[u] += sz[v] + dist[v];
    }
}

void dfs2(int u, int p) // propagate sum of paths from 1 to others
{
    for(int v: Tr[u])
    {
        if(v == p) continue;
        dist[v] = dist[u] + n - 2LL*sz[v];
        dfs2(v, u);
    }
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // note that ans[p] = ans[k] + sz[k] - (n - sz[k])
    // first find the ans for any arbitrary root using in[p] = sum(sz[k] + in[k])
    // then do another traversal to populate the values using the tree DP recurrence
    cin >> n;
    Tr.resize(n+1);
    for(int i=0,a,b; i<n-1; i++){ cin >> a >> b; Tr[a].push_back(b); Tr[b].push_back(a); }
    sz.assign(n+1, 0LL); dist.assign(n+1, 0LL);
    // find answer for 1
    dfs1(1, 0);
    // propagate ans to children with another DFS
    dfs2(1, 0);
    for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
    return 0;
}