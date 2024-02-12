#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int n;
ll S = 0, curS = 0, mindiff = 1000000000000LL;
vector<ll> P;

void backtrack(int k)
{
    if(k==n)
    {
        ll diff = S - 2*curS; if(diff<0) diff = -diff;
        // cout<<diff<<endl;
        mindiff = min(mindiff, diff);
        return;
    }
    curS += P[k];
    backtrack(k+1);
    curS -= P[k];
    backtrack(k+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    P = vector<ll>(n);
    for(int i=0; i<n; i++) { cin >> P[i]; S += P[i]; }
    backtrack(0);
    cout<<mindiff<<endl;
    return 0;
}