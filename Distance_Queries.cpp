#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

template<class T> ostream& operator <<(ostream& os, const vector<T>& v)
{
    for(auto elem: v) os << elem << " "; return os;
}

int n, q;
vector<vector<int>> Tr, ances;
vector<int> depth;

void treeDFS(int u, int p)
{
    for(int v: Tr[u])
    {
        if(v == p) continue;
        depth[v] = 1 + depth[u];
        ances[0][v] = u;
        treeDFS(v, u);
    }
}

int LCA(int a, int b)
{
    if(depth[a]<depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i=0; (1<<i)<=k; i++)
        if(((1<<i)&k)) a = ances[i][a];

    if(a==b) return a;

    int i = 0;
    for(;ances[i][a]!=ances[i][b];i++);
    return LCA(ances[max(i-1,0)][a], ances[max(i-1,0)][b]);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // root the tree, DFS to assign depths, return depth[a] + depth[b] - 2*depth[lca]
    cin >> n >> q;
    Tr.resize(n+1);
    for(int i=0,a,b; i<n-1; i++){ cin >> a >> b; Tr[a].push_back(b); Tr[b].push_back(a); }
    // root the tree, DFS to assign depths and binary lift table
    depth.assign(n+1, 0); ances.assign(30, vector<int>(n+1, 0));
    treeDFS(1, 0);
    for(int i=1; i<30; i++)
        for(int j=1; j<=n; j++)
            ances[i][j] = ances[i-1][ances[i-1][j]];

    for(;q--;)
    {
        int a,b; cin >> a >> b;
        cout << depth[a] + depth[b] - 2*depth[LCA(a,b)] << "\n";
    }
    return 0;
}