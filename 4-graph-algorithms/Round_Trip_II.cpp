#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
 
const int INF = 1e9 + 69;

int n, m;
vector<vector<int>> G;
vector<int> vis, paren;
 
void dfs(int u, int p, int x)
{
    vis[u] = x; paren[u] = p;
    for(int v: G[u])
    {
        if(!vis[v]) dfs(v, u, x);
        else if(vis[v]==x) // bingo
        {
            vector<int> ans;
            for(int l=u;l!=v;l=paren[l]) ans.push_back(l);
            ans.push_back(v); ans.push_back(u);
            reverse(begin(ans), end(ans));
            cout<<ans.size()<<"\n";
            for(int a: ans) cout << a << " ";
            exit(0);
        }
        vis[v] = -1;
    }
}
 
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> m;
    G.resize(n+1);
    for(int i=0,a,b; i<m; i++){ cin >> a >> b; G[a].push_back(b); }
    vis.assign(n+1, 0);
    paren.resize(n+1);
    
    // DFS with trail numbering
    for(int i=1; i<=n; i++)
    {
        if(!vis[i]) dfs(i, 0, i);
        vis[i] = -1;
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}