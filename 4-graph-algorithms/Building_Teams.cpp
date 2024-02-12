#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

#define NMX 100000
int n, m;
vector<int> adj[NMX+1];
queue<int> q;
int team[NMX+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0,u,v;i<m;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    memset(&team, 0, sizeof(team));
    // use an SCC type BFS to color every node
    for(int i=1; i<=n; i++)
    {
        // skip if already coloured
        if(team[i]!=0) continue;
        // apply BFS with alternating color for uncolored nodes
        team[i] = 1; q.push(i);
        for(;!q.empty();)
        {
            int u = q.front(); q.pop();
            for(int v: adj[u])
            {
                if(team[v]==0)
                { team[v]=1+team[u]%2; q.push(v); }
                else if(team[v]==team[u])
                { cout<<"IMPOSSIBLE"<<endl; return 0; }
            }
        }
    }
    for(int i=1; i<=n; i++)
    cout<<team[i]<<" ";
    return 0;
}