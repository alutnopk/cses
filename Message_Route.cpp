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
#define INF 100000000
int n, m;
vector<int> adj[NMX+1];
int paren[NMX+1];
queue<int> q;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int a,b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i=0; i<=n; i++) {paren[i]=-1;}
    // execute BFS from 1 to n
    paren[1]=1; q.push(1);
    for(;!q.empty();)
    {
        int nd = q.front(); q.pop();
        for(int nbr: adj[nd])
        {
            if(paren[nbr]<0)
            { paren[nbr]=nd; q.push(nbr); }
            // if(spath[nd]+1<spath[nbr])
            // { spath[nbr]=spath[nd]+1; q.push(nbr); paren[nbr]=nd;}
        }
    }
    if(paren[n]==-1)
        cout<<"IMPOSSIBLE"<<endl;
    else
    {
        // backtrack using paren
        // cout << spath[n]+1 << endl;
        stack<int> track; int spath=0;
        for(int i=n; i!=1; i=paren[i])
        {
            track.push(i);
            spath++;
        }
        track.push(1); spath++;
        cout<<spath<<endl;
        for(;!track.empty();)
        {
            int _ = track.top(); track.pop();
            cout<<_<<" ";
        }
    }
    return 0;
}