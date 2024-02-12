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
int n, m, nSCC=0;
unordered_set<int> adj[NMX+1];
int vis[NMX+1];
queue<int> q;
vector<int> anchors;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].insert(b); adj[b].insert(a);
    }
    memset(&vis, 0, sizeof(vis));
    // count the number of SCCs, answer is nSCC - 1, add any such edges
    for(int i=1;i<=n;i++) // iterate through nodes
    {
        // skip node if visited
        if(vis[i]) continue;
        // else start a BFS from this node
        vis[i]=1; q.push(i);
        anchors.push_back(i);
        for(;!q.empty();)
        {
            int nd = q.front(); q.pop();
            // iterate through unvisited nbrs and traverse them
            for(int nbr: adj[nd])
            {
                if(!vis[nbr])
                { vis[nbr]=1; q.push(nbr); }
            }
        }
        nSCC++;
    }

    cout<<nSCC-1<<endl;
    for(int i=0; i<nSCC-1; i++)
    {
        cout<<anchors[i]<<" "<<anchors[i+1]<<endl;
    }
    return 0;
}