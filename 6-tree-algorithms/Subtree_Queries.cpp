#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class T> ostream& operator<<(ostream& os, const vector<T>& v)
{
    for(auto elem: v) os << elem << " "; return os;
}

struct SegTree
{
    vector<int> ST;
    SegTree(int n)
    {
        ST.assign(4*n, 0);
    }
    void update(int x, int i, int v, int tl, int tr)
    {
        if(tl==tr && tl==i){ ST[v] = x; return; }
        int tm = tl + (tr-tl)/2;
        if(i<=tm) update(x, i, 2*v, tl, tm);
        else update(x, i, 2*v+1, tm+1, tr);
        ST[v] = ST[2*v] + ST[2*v+1];
    }
    int query(int l, int r, int v, int tl, int tr)
    {
        if(l > r) return 0;
        if(l==tl && r==tr) return ST[v];
        int tm = tl + (tr-tl)/2;
        return query(l, min(r,tm), 2*v, tl, tm) + query(max(l,tm+1), r, 2*v+1, tm+1, tr);
    }
};

int n, q;
vector<vector<int>> Tr;
vector<int> sz, tti, val;

void DFS1(int u, int p)
{
    static int idx = 0;
    tti[u] = ++idx;
    for(int v: Tr[u])
    {
        if(v == p) continue;
        DFS1(v, u);
        sz[tti[u]] += sz[tti[v]];
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // subtree queries -> tree traversal array
    // first DFS: populate a Tree Traversal Index (TTI) vector and sizes
    // then populate the values based on TTI[i]    
    cin >> n >> q;
    vector<int> v(n+1);
    Tr.resize(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];
    for(int i=0,a,b; i<n-1; i++){ cin >> a >> b; Tr[a].push_back(b); Tr[b].push_back(a); }
    sz.assign(n+1, 1); tti.resize(n+1);
    DFS1(1, 0);
    val.resize(n+1);
    for(int i=1; i<=n; i++) val[tti[i]] = v[i];
    v.clear();
    // cerr<<sz<<"\n"<<tti<<"\n"<<val;
    // remember, sz and val are indexed with tree traversal indices and NOT node numbers
    // build sum segment tree of val
    SegTree ST(n);
    for(int i=1; i<=n; i++) ST.update(val[i], i, 1, 1, n);
    // begin processing queries
    for(;q--;)
    {
        int op, s, x; cin >> op >> s;
        switch(op)
        {
            case 1: // PU
            cin >> x;
            ST.update(x, tti[s], 1, 1, n);
            break;
            case 2: // RQ
            // query from indices tti[s] to tti[s] + sz[tti[s]] - 1
            cout << ST.query(tti[s], tti[s]+sz[tti[s]]-1, 1, 1, n) << "\n";
        }
    }
    return 0;
}