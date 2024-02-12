#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

int n;
vector<vector<int>> T;
vector<int> inc, exc;

void dfs(int u, int p)
{
    // iterating to calculate largest unconnected matching
    for(int v: T[u])
    {
        if(v == p) continue;
        dfs(v, u);
        exc[u] += max(exc[v], inc[v]);
    }
    // now, largest connected matching
    for(int v: T[u])
    {
        if(v == p) continue;
        inc[u] = max(inc[u], 1+exc[v]+exc[u]-max(inc[v], exc[v]));
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // Rooted Tree DP with two types of states:
    // max matching of subtree including the root (inc), and that excluding the root (exc)
    // exc[u] = sum(max{inc[v], exc[v]})
    // inc[u] = max(1+exc[v] + (exc[u] - max{inc[v], exc[v]}))
    // ans is max{inc[1], exc[1]}
    cin >> n;
    T.resize(n+1);
    for(int i=0,a,b; i<n-1; i++){ cin >> a >> b; T[a].push_back(b); T[b].push_back(a); }
    inc.assign(n+1, 0); exc.assign(n+1, 0);
    // root the tree at 1
    dfs(1, 0);
    cout<<max(inc[1], exc[1]);
    return 0;
}