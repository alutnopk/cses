#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

int n, m;
vector<vector<int>> G;
vector<int> topo, vis;

void dfs(int u)
{
    vis[u] = true;
    for(int v: G[u])
        if(!vis[v]) dfs(v);
    topo.push_back(u);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    // DAG => Toposort + DP
    // dp[u] = length of longest route till u from city "0"
    cin >> n >> m;
    G.resize(n); vis.assign(n, false);
    for(int _=0,a,b; _<m; _++){ cin >> a >> b; G[a-1].push_back(b-1); }
    // Toposort with DFS
    for(int i=0; i<n; i++)
        if(!vis[i]) dfs(i);
    reverse(begin(topo), end(topo));
    vector<int> dp(n, 0), p(n, -1); // dp[i] is ans for the i'th node
    dp[0] = 1; p[0] = 0;
    for(int u: topo)
    {
        if(!dp[u]) continue;
        for(int v: G[u])
        {
            if(dp[v]<1+dp[u]){ dp[v] = 1+dp[u]; p[v] = u; }
        }
    }
    vector<int> ans;
    for(int u=n-1;u!=0;u=p[u])
    {
        if(u==-1){ cout<<"IMPOSSIBLE\n"; return 0; }
        ans.push_back(u);
    }
    ans.push_back(0);
    cout<<ans.size()<<"\n";
    reverse(begin(ans), end(ans));
    for(int u: ans)
        cout<<u+1<<" ";
    return 0;
}