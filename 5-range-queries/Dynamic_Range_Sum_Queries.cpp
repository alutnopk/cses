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
int n,q;
ll T[4*NMX];
int clg[NMX+1];

// my update function attempt, could use somewhere though
void pontupd(int idx, ll x) // update segment tree at idx with x
{
    int t = clg[n];
    // essentially, traverse the binary representation of idx
    // t+1 total updates
    T[0] += x;
    for(int i=0,tp=0;i<t;i++) // t+1 updates
    {
        tp = 2*tp + 1 + (idx>>(t-i-1))%2;
        T[tp] += x;
    }
}

void upd(int idx, ll x, int v=0, int ta=0, int tb=n-1)
{
    if(ta==tb)
    {
        T[v] = x; return;
    }
    int tm = (ta+tb)/2;
    if(idx<=tm) upd(idx, x, 2*v+1, ta, tm);
    else upd(idx, x, 2*v+2, tm+1, tb);

    T[v] = T[2*v+1] + T[2*v+2];
}

ll qry(int a, int b, int v=0, int ta=0, int tb=n-1)
{
    if(a>b) return 0;
    if(a==ta && tb==b) return T[v];
    int tm = (ta+tb)/2;
    return qry(a, min(b, tm), 2*v+1, ta, tm) + qry(max(a, tm+1), b, 2*v+2, tm+1, tb);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    vector<ll> x(n);

    // populate clg
    clg[1] = 0;
    for(int i=2; i<=n; i++) clg[i] = 1 + clg[(i/2)+(i%2!=0)];

    memset(T, 0, sizeof(T));
    // update each element to segment tree, O(nlogn)
    for(int i=0; i<n; i++) { cin >> x[i]; upd(i, x[i]); }
    // for(int i=0; i<(1<<(clg[n]+1))-1; i++) cout<<T[i]<<" "; cout<<endl;
    // the tree contains 1<<clg[n] elements
    for(int i=0,op; i<q; i++)
    {
        cin >> op;
        switch(op)
        {
            case 1:
            int k; ll u; cin >> k >> u;
            // query at k-1
            upd(k-1, u); // incorrect
            break;
            case 2:
            int a,b; cin >> a >> b; a--, b--;
            cout<<qry(a, b)<<endl;
        }
    }
    return 0;
}