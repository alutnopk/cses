#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
 
int n;
vector<vector<int>> Tr;
vector<int> dist1, dist2;
int mxdpth = 0, e1 = 0, e2 = 0;
 
void dfs(int u, int p, int depth)
{
    if(depth > mxdpth) mxdpth=depth,  e1=u;
    for(int v: Tr[u])
    {
        if(v == p) continue;
        dfs(v, u, depth+1);
    }
    if(e1==0) e1 = u;
}
 
void bfs(int u, vector<int>& dis)
{
    dis.assign(n+1, -1);
    queue<int> q;
    dis[u] = 0; q.push(u);
    for(;q.size();)
    {
        int x = q.front(); q.pop();
        for(int y: Tr[x])
        {
            if(dis[y]!=-1) continue;
            dis[y] = 1 + dis[x];
            q.push(y);
        }
    }
}
 
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // find ends of the diameter
    // do a BFS from each end to every node, return whichever is higher
    cin >> n;
    Tr.resize(n+1);
    for(int i=0,a,b; i<n-1; i++){ cin >> a >> b; Tr[a].push_back(b); Tr[b].push_back(a); }
    // DFS to find ends 1 and 2
    dfs(1, 0, 0);
    e2 = e1; mxdpth = 0;
    dfs(e2, 0, 0);
    // BFS from both
    bfs(e1, dist1); bfs(e2, dist2);
    cerr << e1 << e2 << "\n";
    for(int i=1; i<=n; i++) cout << max(dist1[i], dist2[i]) << " ";
    return 0;
}