#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

const ll INF = 9e17;
vector<vector<ll>> dist;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    int n, m, k; cin >> n >> m >> k;
    vector<vector<array<ll,2>>> G(n+1);
    for(int i=0; i<m; i++)
    {
        ll u,v,w; cin >> u >> v >> w;
        G[u].push_back({v,w}); // dest, weight
    }
    dist.assign(n+1, vector<ll>(k, INF));

    multiset<pair<ll,ll>> pset;
    dist[1][0] = 0; pset.insert({0,1}); // dist, node
    for(;pset.size();)
    {
        // find the smallest unmarked node, mark it, then relax its neighbors
        ll d = begin(pset)->first, u = begin(pset)->second;
        pset.erase(begin(pset));

        if(d > dist[u][k-1]) continue;
        for(auto p: G[u])
        {
            ll v = p[0], e = p[1];
            if(d+e < dist[v][k-1])
            {
                // pset.erase({dist[v][k-1], v});
                dist[v][k-1] = d+e;
                pset.insert({dist[v][k-1], v});
                sort(begin(dist[v]), end(dist[v]));
            }
        }
    }
    for(int i=0; i<k; i++) cout<<dist[n][i]<<" ";
    return 0;
}