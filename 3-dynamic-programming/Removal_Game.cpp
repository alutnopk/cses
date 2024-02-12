#include <bits/stdc++.h>
using namespace std;

const int p7 = 1000000007;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

vector<ll> x;
vector<vector<ll>> memo;

ll solve(int l, int r)
{
    if(l>r) return 0;
    if(memo[l][r]!=-1) return memo[l][r];

    memo[l][r] = max(x[l]-solve(l+1, r), x[r]-solve(l, r-1));
    return memo[l][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    x = vector<ll>(n);
    ll su = 0;
    for(int i=0; i<n; i++) { cin >> x[i]; su += (ll)x[i]; }
    memo = vector<vector<ll>>(n+1, vector<ll>(n+1, -1));
    ll optdiff = solve(0, n-1);
    ll ans = optdiff + (su-optdiff)/2LL;
    cout<<ans<<endl;
    return 0;
}