#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

const ll p7 = 1e9+7;
int n, m;
vector<vector<int>> G;
vector<bool> vis;
vector<int> topo_order;

inline ll modulo(ll a)
{
    ll b = a%p7;
    if(b<0) b += p7;
    return b;
}

void dfs(int u)
{
    vis[u] = true;
    for(int v: G[u])
        if(!vis[v]) dfs(v);
    topo_order.push_back(u);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    // Toposort + DP to find no. of paths from 0 to n-1
    cin >> n >> m;
    G.resize(n);
    for(int i=0,a,b; i<m; i++){ cin >> a >> b; G[a-1].push_back(b-1); }
    // Step 1: Toposort using DFS
    vis.assign(n, false);
    for(int i=0; i<n; i++) if(!vis[i]) dfs(i);
    reverse(begin(topo_order), end(topo_order));
    // Step 2: DP[v]
    vector<ll> dp(n, 0);
    dp[0] = 1LL;
    for(int u: topo_order)
    {
        for(int v: G[u])
            dp[v] = modulo(dp[v]+dp[u]);
    }
    cout<<dp[n-1];
    return 0;
}