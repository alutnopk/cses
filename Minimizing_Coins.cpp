#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll p7 = 1000000007;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    // dp[x] is the state
    // Pull DP: dp[amt] = min(1+{dp[amt-c[i]]})
    // Push DP: 1+dp[amt] -> dp[amt+c[i]] for each c[i]
    vector<int> dp(x+1, INF);
    dp[0] = 0;
    for(int amt=0; amt<=x; amt++)
        for(int c: coins)
            if(amt+c<=x) dp[amt+c] = min(dp[amt+c], 1+dp[amt]);
    cout<<(dp[x]!=INF?dp[x]:-1)<<endl;
    return 0;
}