#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

int n, m;
vector<vector<int>> G, Gi;
vector<int> exit_order;
vector<bool> vis;

void DFS1(int u)
{
    // static int cntr = 0;
    vis[u] = true;
    for(int v: G[u])
    {
        if(vis[v]) continue;
        DFS1(v);
    }
    // texit[u] = ++cntr;
    exit_order.push_back(u);
}
void DFS2(int u)
{
    vis[u] = true;
    for(int v: Gi[u])
    {
        if(vis[v]) continue;
        DFS2(v);
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // strong connectivity check using Kosaraju's algorithm
    cin >> n >> m;
    G.resize(n+1); Gi.resize(n+1);
    for(int i=1,a,b; i<=m; i++){ cin >> a >> b; G[a].push_back(b); Gi[b].push_back(a); }
    // execute a DFS series to populate exit times
    vis.assign(n+1, false);
    for(int i=1; i<=n; i++)
        if(!vis[i]) DFS1(i);
    
    reverse(begin(exit_order), end(exit_order));
    // the condensed graph contains edges from later components to earlier ones
    // so, pick the latest node, do a search in Gi to prevent leaking to other components, and repeat
    vis.assign(n+1, false);
    vector<int> repr;
    for(int i: exit_order)
    {
        if(vis[i]) continue;
        DFS2(i);
        repr.push_back(i);
    }
    if((int)repr.size() == 1){ cout<<"YES\n"; return 0; }
    cout << "NO\n";
    cout << *(end(repr)-1) << " " << *(end(repr)-2);
    return 0;
}