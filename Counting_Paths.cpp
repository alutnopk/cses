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
vector<vector<int>> Tr, up;
vector<int> val, depth;

void DFS1(int u, int p) // for binary lift and depth
{
    for(int v: Tr[u])
    {
        if(v == p) continue;
        up[v][0] = u;
        for(int j=1; j<(1+__lg(n)); j++)
            up[v][j] = up[up[v][j-1]][j-1];
        depth[v] = 1 + depth[u];
        DFS1(v, u);
    }
}

void DFS2(int u, int p) // to paint the nodes along the parents
{
    for(int v: Tr[u])
    {
        if(v == p) continue;
        DFS2(v, u);
        val[u] += val[v];
    }
}

int LCA(int a, int b)
{
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i=0; (1<<i)<=k; i++) if(((1<<i)&k)) a = up[a][i];
    if(a==b) return a;
    int j=0; for(;up[a][j]!=up[b][j];j++);
    return LCA(up[a][max(j-1,0)], up[b][max(j-1,0)]);
}


int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // Partial sum updates at endpoints and LCA
    // Distribute the changes using a DFS
    cin >> n >> q;
    Tr.resize(n+1);
    for(int i=0,a,b; i<n-1; i++){ cin >> a >> b; Tr[a].push_back(b); Tr[b].push_back(a); }
    // populate binary lifts and depths
    up.assign(n+1, vector<int>((1+__lg(n)), 0));
    depth.assign(n+1, 0);
    DFS1(1, 0);
    // To record a path from a to b, color a and b with +1, and the LCA and its parent with -1
    // the idea is, while painting upwards with a DFS, all nodes on the path a,b shall be colored with 1
    // to block the color from going beyond the LCA, the extra -1 is introduced
    val.assign(n+1, 0);
    for(int a,b;q--;)
    {
        cin >> a >> b;
        int lca = LCA(a,b);
        val[a]++; val[b]++;
        val[lca]--; val[up[lca][0]]--;
    }
    DFS2(1, 0);
    for(int i=1; i<=n; i++) cout << val[i] <<" ";
    return 0;
}