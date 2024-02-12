#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
 
#define NMX 200000
 
ll X[NMX];
ll ST[30][NMX];
ll flog[NMX+1];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, q; cin >> n >> q;
    for(ll i=0; i<n; i++) cin >> X[i];
    // pre-compute the sparse table storing minimum values for power-of-2 ranges
    memset(ST, -1, sizeof(ST));
    for(ll j=0;j<n;j++) ST[0][j] = X[j];
    for(ll i=1;(1<<i)<=n;i++)
    {
        for(ll j=0; j+(1LL<<i)<=n; j++)
        {
            // read ST[i][j] as the range starting from j of size 2^i
            ST[i][j] = min(ST[i-1][j], ST[i-1][j+(1<<(i-1))]);
        }
    }
    // implement floor(log2())
    flog[1] = 0;
    for(ll i=2; i<=n; i++)
    {
        flog[i] = 1 + flog[i/2];
    }
    for(ll i=0,a,b,t; i<q; i++)
    {
        cin >> a >> b; a--, b--;
        t = flog[b-a+1];
        cout<<min(ST[t][a], ST[t][b-(1<<t)+1])<<endl;
    }
    return 0;
}