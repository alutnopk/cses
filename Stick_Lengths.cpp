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
    vector<ll> p(n);
    ll S = 0;
    for(int i=0; i<n; i++) { cin >> p[i]; S += p[i]; }
    sort(p.begin(), p.end());
    ll prefS = 0, minC = 1000000000000000;
    for(int i=0; i<n; i++)
    {
        prefS += p[i];
        minC = min(minC, (2LL*i+2LL-(ll)n)*p[i]+S-2LL*prefS);
    }
    cout<< minC << endl;
    return 0;
}