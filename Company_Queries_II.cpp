#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

template<class T> ostream& operator <<(ostream& os, const vector<T>& v) { for(auto elem: v) os << elem << " "; return os; }

int n,q;
vector<vector<int>> Tr, anc;
vector<int> depth;

void treeDFS(int u, int p)
{
    for(int v: Tr[u])
    {
        if(v == p) continue;
        depth[v] = 1 + depth[u];
        treeDFS(v, u);
    }
}

int LCA(int a, int b)
{
    if(depth[a] < depth[b]) swap(a, b);

    int k = depth[a] - depth[b];
    for(int i=0; (1<<i)<=k; i++)
        if(((1<<i)&k)) a = anc[i][a];

    if(a==b) return a;
    int i = 0;
    for(; anc[i][a]!=anc[i][b]; i++);
    return LCA(anc[max(i-1,0)][a], anc[max(i-1,0)][b]);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // standard LCA
    cin >> n >> q;
    anc.assign(30, vector<int>(n+1, 0));
    Tr.resize(n+1);
    for(int i=2; i<=n; i++){ cin >> anc[0][i]; Tr[anc[0][i]].push_back(i); }
    // pre-process the big daddies
    for(int i=1; i<30; i++)
        for(int j=1; j<=n; j++)
            anc[i][j] = anc[i-1][anc[i-1][j]];
    // DFS from root to assign depths
    depth.assign(n+1, 0);
    treeDFS(1, 0);
    // cerr << depth;
    // LCA pseudocode:
    // bring both nodes to the same level
    // if they're different, find the largest 2'th ancestor which is different for both
    // update positions and repeat until they match
    for(;q--;)
    {
        int a,b; cin >> a >> b;
        int c = LCA(a, b);
        cout << max(c,1) << "\n";
    }
    return 0;
}