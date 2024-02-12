#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

template<class T> ostream& operator<<(ostream& os, const vector<T>& v)
{
    for(auto e: v) os << e << " "; return os;
}

int n, m;
vector<vector<int>> G, Gi;
vector<int> topo_sort, compo;
vector<bool> vis;

void DFS1(int u)
{
    vis[u] = true;
    for(int v: G[u])
        if(!vis[v]) DFS1(v);
    topo_sort.push_back(u);
}

void DFS2(int u, int cntr)
{
    compo[u] = cntr;
    for(int v: Gi[u])
        if(!compo[v]) DFS2(v, cntr);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    // SCC using Kosaraju
    cin >> n >> m;
    G.resize(n+1); Gi.resize(n+1);
    for(int i=0,a,b;i<m; i++){ cin >> a >> b; G[a].push_back(b); Gi[b].push_back(a); }
    // first DFS series to determine exit orders
    vis.assign(n+1, false);
    for(int i=1; i<=n; i++)
        if(!vis[i]) DFS1(i);
    reverse(begin(topo_sort), end(topo_sort));
    // in descending orders of t_exit (which is also the toposort order for the condensed graph)
    // we color all components of this SCC using Gi, and we know this'll work cuz toposort of condensed graph
    compo.assign(n+1, 0);
    int cntr = 0;
    for(int i: topo_sort)
    {
        if(!compo[i])
            DFS2(i, ++cntr);
    }
    cout << cntr << "\n";
    for(int i=1; i<=n; i++) cout << compo[i] << " ";
    return 0;
}