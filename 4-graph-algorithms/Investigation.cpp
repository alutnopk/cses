#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
 
const ll INF = 9e18;
const ll p7 = 1e9+7;
 
inline ll modulo(ll a){ return a%p7 + ((a%p7<0)?p7:0LL); }
 
struct Edge { int v; ll e; };
vector<ll> dist;
struct Comparator
{
    bool operator()(const int& u, const int& v) const
    {
        if(dist[u]!=dist[v]) return dist[u] < dist[v];
        else return u < v;
    }
};
 
int n, m;
vector<vector<Edge>> G;
vector<ll> dp1, dp2, dp3;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    // Dijkstra-guided DP
    cin >> n >> m;
    G.resize(n);
    for(int i=0; i<m; i++){ int u,v; ll e; cin >> u >> v >> e; G[u-1].push_back({v-1, e}); }
    dist.assign(n, INF);
    set<int, Comparator> pset;
    dist[0] = 0; pset.insert(0);
    dp1.assign(n, 0); dp2.assign(n, INF); dp3.assign(n, -INF);
    dp1[0] = 1LL; dp2[0] = 0LL; dp3[0] = 0LL;
    for(;pset.size();)
    {
        int u = *(begin(pset)); pset.erase(begin(pset));
        for(auto edg: G[u])
        {
            int v = edg.v; ll e = edg.e;
            if(dist[u]+e<=dist[v])
            {
                if(dist[u]+e<dist[v]){ dp1[v]=0; dp2[v]=INF; dp3[v]=-INF; }
                pset.erase(v);
                dist[v] = dist[u] + e;
                dp1[v] = modulo(dp1[v]+dp1[u]); // no. of shortest routes
                dp2[v] = min(dp2[v], 1LL+dp2[u]); // min. no of flights
                dp3[v] = max(dp3[v], 1LL+dp3[u]); // max. no of flights
                pset.insert(v);
            }
        }
    }
    cout<<dist[n-1]<<" "<<dp1[n-1]<<" "<<dp2[n-1]<<" "<<dp3[n-1];
    return 0;
}