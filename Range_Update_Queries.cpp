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

void upd(int xl, int xr, ll x, int v=0, int TL=0, int TR=n-1)
{
    // add the value x to the range [xl, xr]
    if(xl>xr) return;
    if(xl==TL && xr==TR){ T[v]+=x; return; }

    int TM = (TL+TR)/2;
    upd(xl, min(TM, xr), x, 2*v+1, TL, TM);
    upd(max(TM+1, xl), xr, x, 2*v+2, TM+1, TR);
}

ll qry(int ix, int v=0, int TL=0, int TR=n-1)
{
    if(TL==TR) return T[v];
    int TM = (TL+TR)/2;
    if(ix<=TM) return T[v] + qry(ix, 2*v+1, TL, TM);
    else return T[v] + qry(ix, 2*v+2, TM+1, TR);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    vector<ll> X(n);
    memset(T, 0, sizeof(T));
    for(int i=0; i<n; i++){ cin >> X[i]; upd(i, i, X[i]); }

    for(int i=0, op; i<q; i++)
    {
        cin >> op;
        switch(op)
        {
            case 1: // update
            int a, b; ll u; cin >> a >> b >> u;
            upd(a-1, b-1, u);
            break;
            case 2: // query
            int k; cin >> k;
            cout<<qry(k-1)<<endl;
        }
    }
    return 0;
}