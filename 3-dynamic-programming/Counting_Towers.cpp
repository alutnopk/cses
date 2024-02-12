#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll p7 = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int _; cin >> _;
    vector<vector<ll>> dp(1000000+1, vector<ll>(3));
    while(_--)
    {
        int n; cin >> n;
        // dp[i][1] represents states that don't have a vertical bar at the top
        // dp[i][2] states have a vertical bar at the top
        dp[1][1] = dp[1][2] = 1;
        for(int i=2; i<=n; i++)
        {
            dp[i][1] = ((4*dp[i-1][1]) + dp[i-1][2])%p7;
            dp[i][2] = (dp[i-1][1] + (2*dp[i-1][2]))%p7;
        }
        cout<<(dp[n][1]+dp[n][2])%p7<<endl;
    }
    return 0;
}