#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll p7 = 1000000007;
const ll INF = 1e17;
const ll NINF = -INF;

int n, m;
vector<array<ll, 3>> edges;
vector<ll> dist;

inline ll min_ll(ll a, ll b) { return (a<b)?a:b; }
inline ll max_ll(ll a, ll b) { return (a>b)?a:b; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    edges.resize(m);
    for(int i=0; i<m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][2] = -edges[i][2];
    }
    // n-1 passes of Bellman Ford
    dist.assign(n+1, INF); dist[1] = 0LL;
    for(int _n=1; _n<=n-1; _n++)
    {
        for(auto tr: edges)
        {
            ll u, v, d; u = tr[0], v = tr[1], d = tr[2];
            if(dist[u]<INF) dist[v] = min_ll(dist[v], d+dist[u]);
        }
    }
    // this is where the fun begins
    // do one more pass to detect atleast 1 node that belongs to a -ve cycle
    // label it NINF
    // apply n-1 relaxations again to propagate the -NINF to all the victim nodes

    // NINF insertion pass + Second Bellman-Ford
    for(int _n=1; _n<=n; _n++)
    {
        for(auto tr: edges)
        {
            ll u, v, d; u = tr[0], v = tr[1], d = tr[2];
            if(dist[u]==INF) continue;
            // dist[v] = min_ll(dist[v], d+dist[u]);
            // dist[v] = max_ll(dist[v], NINF);
            if(dist[v]>d+dist[u]) // bingo
                dist[v] = NINF;
        }
    }
    cout<<((dist[n]!=NINF)?-dist[n]:-1)<<endl;
    return 0;
}