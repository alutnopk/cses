#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC target ("arch=sandybridge")
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
    
    string sn, sm;
    int n, m;
    cin >> sn >> sm;
    n = sn.size(); m = sm.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    dp[0][0] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int j=0; j<=m; j++) dp[0][j] = j;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(sn[i-1]==sm[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}