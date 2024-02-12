#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll p7 = 1000000007;
const ll INF = 1e18;

typedef struct { ll v, d; } Edge;
typedef struct { ll d, i, v; } State;

int n, m;
vector<vector<array<ll,2>>> G;
set<array<ll,3>> pset;
vector<vector<ll>> dp;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // perhaps Dijkstra with DP(n, 0/1) to determine the optimal choice
    cin >> n >> m;
    G.resize(n);
    for(int _=0; _<m; _++)
    {
        ll u, v, d; cin >> u >> v >> d; u--, v--;
        G[u].push_back({v,d});
    }
    dp.assign(n, vector<ll>(2, INF)); // dp(i, j) is min cost to travel to i, with/without discount used
    // Dijkstra
    dp[0][0] = 0;
    pset.insert({0,0,0});
    for(;pset.size();)
    {
        auto s1 = *(pset.begin()); pset.erase(pset.begin());
        // ll u = s1.v, used = s1.i;
        for(auto edg: G[s1[2]])
        {
            // push this state to future states
            // dp[s1.v][s1.i] -> dp[edg.v][s1.i] or dp[edg.v][s1.i]
            if(s1[1]==0) // not yet used
            {
                if(edg[1] + dp[s1[2]][0] < dp[edg[0]][0])
                {
                    pset.erase({dp[edg[0]][0], 0, edg[0]});
                    dp[edg[0]][0] = edg[1] + dp[s1[2]][0];
                    pset.insert({dp[edg[0]][0], 0, edg[0]});
                }
                if((edg[1])/2 + dp[s1[2]][0] < dp[edg[0]][1])
                {
                    pset.erase({dp[edg[0]][1], 1, edg[0]});
                    dp[edg[0]][1] = (edg[1])/2 + dp[s1[2]][0];
                    pset.insert({dp[edg[0]][1], 1, edg[0]});
                }
                // dp[edg[0]][0] = min(dp[edg[0]][0], edg[1] + dp[s1[2]][0]);
                // dp[edg[0]][1] = min(dp[edg[0]][1], (edg[1])/2 + dp[s1[2]][0]);
            }
            else
            {
                // dp[edg[0]][1] = edg[1] + dp[s1[2]][1];
                if(edg[1] + dp[s1[2]][1] < dp[edg[0]][1])
                {
                    pset.erase({dp[edg[0]][1], 1, edg[0]});
                    dp[edg[0]][1] = edg[1] + dp[s1[2]][1];
                    pset.insert({dp[edg[0]][1], 1, edg[0]});
                }
            }
        }
    }
    cout<<dp[n-1][1]<<endl;
    return 0;
}