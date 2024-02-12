#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> state, paren;
// td, tf;

void checkedge(int u, int v)
{
    if(state[v] == 1 && v!=paren[u]) // if backedge
    {
        vector<int> ans;
        for(int x=u;x!=v;x=paren[x]) ans.push_back(x);
        ans.push_back(v); ans.push_back(u);
        cout << ans.size() << "\n";
        for(int a: ans) cout << a << " ";
        exit(0);
    }
}

void DFS(int u)
{
    // static int timer = 0;
    state[u] = 1; // td[u] = ++timer;
    // discover(u)
    for(int v: G[u])
    {
        // process edge u, v
        checkedge(u, v);
        if(!state[v]) { paren[v] = u; DFS(v); }
    }
    state[u] = 2; // tf[u] = ++timer;
    // finish(u)
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    G.assign(n+1, vector<int>());
    for(int i=0,a,b; i<m; i++){ cin >> a >> b; G[a].push_back(b); G[b].push_back(a); }
    paren.assign(n+1, 0); state.assign(n+1, 0);
    for(int i=1; i<=n; i++)
        if(!state[i]) DFS(i);
    cout << "IMPOSSIBLE\n";
    return 0;
}