#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

int n;
vector<vector<int>> G;
vector<int> subno;

int num_subord(int u)
{
    if(subno[u]!=-1) return subno[u];
    subno[u] = 1;
    for(int v: G[u])
    { subno[u] += num_subord(v); }
    return subno[u];
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n;
    G.resize(n);
    for(int i=1,x; i<=n-1; i++) { cin >> x; G[x-1].push_back(i); }
    subno.assign(n, -1);
    num_subord(0);
    for(int sn: subno) cout<<sn-1<<" ";
    return 0;
}