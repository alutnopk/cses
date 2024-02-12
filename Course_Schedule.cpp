#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

int n, m;
vector<vector<int>> G;
vector<int> indeg;
queue<int> q;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n >> m;
    G.resize(n+1);
    indeg.assign(n+1, 0);
    for(int i=0,a,b; i<m; i++){ cin >> a >> b; G[a].push_back(b); indeg[b]++; }
    // Kahn's BFS
    for(int i=1; i<=n; i++) if(!indeg[i]) q.push(i);
    vector<int> ans;
    for(;q.size();)
    {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(int v: G[u])
        {
            indeg[v]--;
            if(!indeg[v]) q.push(v);
        }
    }

    if(ans.size()<n){ cout<<"IMPOSSIBLE\n"; return 0; }
    for(int a: ans) cout << a << " ";

    return 0;
}