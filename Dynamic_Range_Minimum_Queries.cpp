#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int NMX = 200000;
int n, q;
ll T[4*NMX];

void upd(int tx, ll x, int v=0, int tl=0, int tr=n-1) // recursive update function
{
    // base case: leaf node [tx, tx] found
    if(tl==tr) { T[v] = x; return; }
    int tm = (tl+tr)/2;
    // recursion: call function on left/right subtree
    if(tx<=tm) upd(tx, x, 2*v+1, tl, tm);
    else upd(tx, x, 2*v+2, tm+1, tr);
    // solve current node using children
    T[v] = min(T[2*v+1], T[2*v+2]);
}
ll qry(int l, int r, int v=0, int tl=0, int tr=n-1) // recursive query evaluation
{
    // if(l>r) return 1000000000000000L;
    if(l==tl && r==tr) return T[v];
    // cout<<"a="<<l<<"b="<<r<<endl;
    int tm = (tl+tr)/2;
    // return min(qry(l, min(tm, r), 2*v+1, tl, tm), qry(max(l, tm+1), r, 2*v+2, tm+1, tr));
    if(r<=tm) return qry(l, r, 2*v+1, tl, tm);
    else if(l>=tm+1) return qry(l, r, 2*v+2, tm+1, tr);
    else return min(qry(l, tm, 2*v+1, tl, tm), qry(tm+1, r, 2*v+2, tm+1, tr));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        
    cin >> n >> q;
    // memset(T, 2000000000, sizeof(T));
    vector<ll> X(n);
    for(int i=0; i<n; i++) { cin >> X[i]; upd(i, X[i]); }
    for(int i=0, op; i<q; i++)
    {
        cin >> op;
        switch(op)
        {
            case 1: // update pos k to u
            int k; ll u; cin >> k >> u;
            upd(k-1, u);
            break;
            case 2: // query [a, b]
            int a, b; cin >> a >> b; a--, b--;
            cout<<qry(a, b)<<endl;
        }
    }
    return 0;
}