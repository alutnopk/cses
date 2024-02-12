#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

struct SegmentTree
{
    vector<ll> ST;
    SegmentTree(int n){ ST.assign(4*n, 0ll); }
    void update(ll x, int l, int r, int v, int tl, int tr)
    {
        if(l > r) return;
        if(l==tl && r==tr) { ST[v] += x; return; }
        int tm = tl + (tr-tl)/2;
        update(x, l, min(r, tm), 2*v, tl, tm);
        update(x, max(l, tm+1), r, 2*v+1, tm+1, tr);
    }
    ll query(int idx, int v, int tl, int tr)
    {
        if(tl == tr && tl == idx) return ST[v];
        int tm = tl + (tr-tl)/2;
        ll ans = ST[v];
        if(idx<=tm)
            ans += query(idx, 2*v, tl, tm);
        else
            ans += query(idx, 2*v+1, tm+1, tr);
        return ans;
    }
};

int n, q;
vector<vector<int>> Tr;
vector<int> tti, sz;

void DFS(int u, int p)
{
    static int idx = 0;
    tti[u] = ++idx;
    for(int v: Tr[u])
    {
        if(v == p) continue;
        DFS(v, u);
        sz[tti[u]] += sz[tti[v]];
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // tree traversal array that stores sum of path from root to each node
    // steps:
    // execute DFS to number the nodes and also find subtree sizes
    // next, use a segment tree to support range updates and point queries
    // sheesh this will be a big one
    cin >> n >> q;
    vector<ll> vec(n+1);
    for(int i=1; i<=n; i++) cin >> vec[i];
    Tr.resize(n+1);
    for(int i=1,a,b; i<n; i++){ cin >> a >> b; Tr[a].push_back(b); Tr[b].push_back(a); }
    // DFS to assign traversal orders and sizes (sizes must be indexed with tti)
    tti.assign(n+1, 0); sz.assign(n+1, 1);
    DFS(1, 0);
    // cerr << v << "\n" << tti << "\n" << sz << "\n\n";
    // build RUPQ segment tree on val, again indexed on tti
    SegmentTree ST(n);
    for(int i=1; i<=n; i++) ST.update(vec[i], tti[i], tti[i]+sz[tti[i]]-1, 1, 1, n);
    // for(ll i=1; i<=n; i++) cerr << ST.query(i, 1, 1, n) << " "; cerr << "\n"; cerr << "\n";
    // begin processing queries
    for(;q--;)
    {
        int op, s; ll x;
        cin >> op >> s;
        switch(op)
        {
            case 1: // RU
            cin >> x;
            ST.update(x-vec[s], tti[s], tti[s]+sz[tti[s]]-1, 1, 1, n);
            vec[s] = x; // THIS IS IMPORTANT
            // for(ll i=1; i<=n; i++) cerr << ST.query(i, 1, 1, n) << " "; cerr << "\n";
            break;
            case 2: // PQ
            cout << ST.query(tti[s], 1, 1, n) << "\n";
        }
    }
    return 0;
}