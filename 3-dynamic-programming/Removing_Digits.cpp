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

#define NMAX 1000000
int memo[NMAX + 1];

int solve(int n)
{
    // memo lookup
    if(memo[n] != -1) return memo[n];
    // base case
    if(n == 0){ memo[n] = 0; return 0; }
    // loop and recursion
    int min_hop = 10*NMAX, ncpy = n;
    for(;ncpy>0; ncpy/=10)
    {
        if(ncpy%10 == 0) { continue; }
        min_hop = min(min_hop, solve(n-(ncpy%10)));
    }
    memo[n] = 1 + min_hop;
    return memo[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i=0; i<=NMAX; i++) memo[i] = -1;
    cout<<solve(n)<<endl;
    return 0;
}