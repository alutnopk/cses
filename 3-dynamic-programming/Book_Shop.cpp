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

#define XMAX 100000
#define NMAX 1000
int dp[XMAX+1];

// solve(x) represents the max pages purchasable with budget x
int solve(const vector<int>& price, const vector<int>& pages, int n, int x)
{
    for(int i=0; i<n; i++)
    {
        // each iteration represents a "row" in the uncollapsed dp array
        for(int j=x; j>=price[i]; j--)
        {
            dp[j] = max(dp[j], pages[i]+dp[j-price[i]]);
        }
    }
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x; cin >> n >> x;
    vector<int> price(n);
    vector<int> pages(n);
    for(int i=0; i<n; i++)
        cin >> price[i];
    for(int i=0; i<n; i++)
        cin >> pages[i];
    
    cout<<solve(price, pages, n, x)<<endl;
    return 0;
}