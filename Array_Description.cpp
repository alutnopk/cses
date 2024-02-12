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
    vector<ll> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    vector<vector<ll>> dp(m+1, vector<ll>(n+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(i==1)
            {
                if(A[i-1]==j || A[i-1]==0)
                    dp[j][i] = 1;
            }
            else
            {
                if(A[i-1]==j || A[i-1]==0)
                {
                    dp[j][i] = dp[j][i-1];
                    if(j>1) dp[j][i] = (dp[j][i]+dp[j-1][i-1])%p7;
                    if(j<m) dp[j][i] = (dp[j][i]+dp[j+1][i-1])%p7;
                }
            }
        }
    }
    ll tot=0;
    for(int j=1; j<=m; j++)
    {
        tot = (tot+dp[j][n])%p7;
    }
    cout<<tot<<endl;
    return 0;
}