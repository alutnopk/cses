#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> num(n), idx(n);
    for(int i=0; i<n; i++) { cin >> num[i]; num[i]--; idx[num[i]]=i; }
    int rnds=1, lastidx = idx[0];
    for(int i=0; i<n; i++)
    {
        if(idx[i] < lastidx) rnds++;
        lastidx = idx[i];
    }
    // update rndc based on queries
    for(int i=0,a,b,tmp,na,nb; i<m; i++)
    {
        cin >> a >> b; a--, b--;
        tmp = num[a]; num[a] = num[b]; num[b] = tmp;
        na = num[a]; nb = num[b];
        tmp = idx[na]; idx[na] = idx[nb]; idx[nb] = tmp;
        // rnds -= (((na>0)?idx[na-1]:-1)>idx[na]) + (idx[na]>((na<n-1)?idx[na+1]:n+1)) + (((nb>0)?idx[nb-1]:-1)>idx[nb]) + (idx[nb]>((nb<n-1)?idx[nb+1]:n+1));
        // cerr<<rnds<<endl;
        // for(int j=0; j<n; j++) cerr<<idx[j]<<" "; cerr<<endl;
        // cerr<<na<<" "<<nb<<endl;
        // // check na-1, na, na+1 etc etc
        // rnds += (((na>0)?idx[na-1]:-1)>idx[na]) + (idx[na]>((na<n-1)?idx[na+1]:n+1)) + (((nb>0)?idx[nb-1]:-1)>idx[nb]) + (idx[nb]>((nb<n-1)?idx[nb+1]:n+1));
        // cout<<rnds<<endl;
        rnds = 1; lastidx = idx[0];
        for(int j=0; j<n; j++)
        {
            if(idx[j] < lastidx) rnds++;
            lastidx = idx[j];
        }
        cout<<rnds<<endl;
    }
    return 0;
}