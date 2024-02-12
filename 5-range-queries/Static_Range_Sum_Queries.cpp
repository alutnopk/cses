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
    
    int n, q; cin >> n >> q;
    vector<int> x(n);
    vector<ll> prefsum(n);
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
    }
    // populate prefix sums
    ll term=0;
    for(int i=0; i<n; i++)
    {
        term += x[i];
        prefsum[i] = term;
    }
    // a query of the form [a, b] can be answered as:
    // prefsum[b] - prefsum[a-1]
    ll res;
    for(int i=0,a,b; i<q; i++)
    {
        cin >> a >> b; --a; --b;
        res = prefsum[b] - (a>0)*prefsum[a-1];
        cout<<res<<endl;
    }
    return 0;
}