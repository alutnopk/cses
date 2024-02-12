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

const int X = 1e6;
const int INF = 1e7;
int dp[X];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x; cin >> n >> x;
    vector<int> coin(n);
    for(int i=0; i<n; i++)
    {
        cin >> coin[i];
    }
    dp[0] = 1;
    for(int i=1; i<=x; i++)
    {
        dp[i] = 0;
        for(int c: coin)
        {
            if(c<=i)
                dp[i] = (dp[i]+dp[i-c])%p7;
        }
    }
    cout<< dp[x] << endl;
    return 0;
}