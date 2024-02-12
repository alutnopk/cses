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

void upd(int ix, ll x, int v=0, int TL=0, int TR=n-1)
{
    // base case
    if(TL==TR){ T[v]=x; return; }

    int TM = (TL+TR)/2;
    if(ix<=TM) upd(ix, x, 2*v+1, TL, TM);
    else upd(ix, x, 2*v+2, TM+1, TR);

    T[v] = T[2*v+1]^T[2*v+2];
}

ll qry(int a, int b, int v=0, int TL=0, int TR=n-1)
{
    if(TL==a && TR==b) return T[v];
    int TM = (TL+TR)/2;
    if(b<=TM) return qry(a, b, 2*v+1, TL, TM);
    else if(a>TM) return qry(a, b, 2*v+2, TM+1, TR);
    else return qry(a, TM, 2*v+1, TL, TM)^qry(TM+1, b, 2*v+2, TM+1, TR);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    vector<ll> X(n);
    for(int i=0; i<n; i++){ cin >> X[i]; upd(i, X[i]);}

    for(int i=0, a, b; i<q; i++)
    {
        cin >> a >> b; a--, b--;
        cout << qry(a, b) << endl;
    }
    return 0;
}