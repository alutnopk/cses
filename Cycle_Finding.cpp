#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll p7 = 1000000007;
const ll INF = 1e18;

inline ll min_ll(ll a, ll b) { return (a<b)?a:b; }
inline ll max_ll(ll a, ll b) { return (a>b)?a:b; }

int n, m;
vector<array<ll, 3>> edges;
vector<ll> dist, paren;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    edges.resize(m);
    for(int _=0; _<m; _++) cin >> edges[_][0] >> edges[_][1] >> edges[_][2];
    // initialize dist with 0 everywhere to search for _any_ -ve cycle
    // (n-1) relaxation passes + 1 pass to find any rogue node
    // traverse its parents n times, and then loop again to obtain a cycle
    dist.assign(n+1, 0LL);
    paren.resize(n+1); generate(begin(paren), end(paren), [](){static ll i=0; return i++;});
    ll x = 0;
    for(int _=1; _<=n; _++)
    {
        for(auto edg: edges)
        {
            ll u, v, d; u = edg[0], v = edg[1], d = edg[2];
            if(dist[u]+d<dist[v])
            {
                dist[v] = max_ll(-INF, dist[u]+d);
                paren[v] = u;
                if(_==n) x = v;
            }
        }
    }
    if(!x){ cout<<"NO"<<endl; return 0; }
    cout<<"YES\n";
    // go back n places
    for(int _=0;_<n;_++) x = paren[x];
    // backtrack from here to get a loop
    vector<ll> ans;
    for(ll u=x;1;u=paren[u])
    {
        ans.push_back(u);
        if(u==x && ans.size()>1) break;
    }
    reverse(begin(ans), end(ans));
    for(ll a: ans) cout<<a<<" "; cout<<endl;
    return 0;
}