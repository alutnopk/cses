#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

int n;
vector<int> SG, ans;
vector<vector<int>> RG;

struct DSU
{
    vector<int> paren, sz;
    DSU(int n)
    {
        paren.resize(n+1); //generate(begin(paren), end(paren), [](){static int i; return i++;});
        for(int i=1; i<=n; i++) paren[i] = i;
        sz.assign(n+1, 1);
    }
    int find(int u)
    {
        if(u == paren[u]) return u;
        else return paren[u] = find(paren[u]);
    }
    bool unite(int a, int b) // unite a to b
    {
        a = find(a), b = find(b);
        if(a==b) return false;
        if(sz[a]>sz[b]) swap(a, b);
        paren[a] = b; sz[b] += sz[a];
        return true;
    }
};

void floyd(int u)
{
    // cerr<<"u:"<<u<<"\n";
    int x,y; x = SG[u], y = SG[SG[u]];
    // find any node in the loop
    for(;x!=y;) { x = SG[x]; y = SG[SG[y]]; }
    cerr<<x<<"\n";
    // determine the length
    int l = 1, z = SG[x];
    for(;z!=x;){ z = SG[z]; l++; }
    cerr<<l<<"\n";
    // cerr<<"l:"<<l<<"\n";
    // assign length to every loop node
    // gonna try multi-source BFS here
    queue<int> q;
    ans[x] = l; q.push(x);
    for(z=SG[x];z!=x;z=SG[z]) { ans[z] = l; q.push(z); }
    // use the reverse graph (some kinda weird Fibonacci forest) to propagate the loop length + distance to the branches
    for(;q.size();)
    {
        int d = q.front(); q.pop();
        for(int e: RG[d])
        {
            if(ans[e] == ans[d]) continue;
            ans[e] = 1 + ans[d];
            q.push(e);
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // use a DSU to represent the set of components
    // find the cycle size of each component using Floyd's traversal
    cin >> n;
    SG.resize(n+1); RG.resize(n+1);
    for(int i=1; i<=n; i++) { cin >> SG[i]; RG[SG[i]].push_back(i); }
    // first, build a DSU representing each component
    DSU dsu(n);
    // for(int i=1; i<=n; i++) cout<<dsu.find(i)<<" ";
    for(int i=1; i<=n; i++) dsu.unite(i, SG[i]);
    // next, run floyd on each component
    ans.assign(n+1, 0);
    // map<int, int> m;
    set<int> compo;
    for(int i=1; i<=n; i++)
    {
        int lead = dsu.find(i);
        if(compo.find(lead) == end(compo)) { floyd(i); compo.insert(lead); }
    }
    
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    return 0;
}