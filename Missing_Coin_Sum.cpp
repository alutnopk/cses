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
    
    int n; cin >> n;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    ll res = 1;
    for(int i=0; i<n; i++)
    {
        if(res < x[i]){ cout<<res; return 0; }
        res += x[i];
    }
    cout<<res;
    return 0;
}