#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll p7 = 1000000007LL;
vector<vector<ll>> memo;

ll solve(int n, int s)
{
    if(s<0) return 0;
    if(memo[n][s]!=-1) return memo[n][s];
    if(s==0){ memo[n][s]=1; return 1LL; }
    if(n==0){ memo[n][s]=0; return 0; }
    memo[n][s] = (solve(n-1, s-n)+solve(n-1, s))%p7;
    return memo[n][s];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int s = (n*(n+1))/2;
    if(s%2) { cout<<0<<endl; return 0; }
    s /= 2;
    memo = vector<vector<ll>> (n+1, vector<ll>(s+1, -1));
    cout<<(solve(n, s)*(p7+1)/2LL)%p7<<endl;
    return 0;
}