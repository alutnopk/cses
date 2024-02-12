#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

const int INF = 1e9 + 69;

int n;
vector<vector<int>> T;
vector<int> maxdepth, maxdiam;

int solve(int u, int p)
{
    if(maxdepth[u]!=-1) return maxdepth[u];
    maxdiam[u] = maxdepth[u] = 0;
    vector<int> max2;
    for(int v: T[u])
    {
        if(v==p) continue;
        int vlen = solve(v, u);
        maxdepth[u] = max(maxdepth[u], 1+vlen);
        // find 2 longest subchains
        if(max2.size()<2) { max2.push_back(vlen); continue; }
        if(vlen>max2[0]){ max2[1] = max2[0]; max2[0] = vlen; }
        else if(vlen<=max2[0] && vlen>=max2[1]){ max2[1] = vlen; }
    }
    for(int mx: max2) maxdiam[u] += 1 + mx;
    return maxdepth[u];
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> n;
    T.resize(n+1);
    for(int i=0,a,b; i<n-1; i++){ cin >> a >> b; T[a].push_back(b); T[b].push_back(a); }
    // this approach uses multi-DP using max depth and max diameter to determine the answer
    // maxdepth[u] = 1 + max(maxdepth[v])
    // maxdiam[u] = 2 + sum of two largest maxdepths among children
    maxdepth.assign(n+1, -1); maxdiam.assign(n+1, -1);
    // root the tree at 1 and recurse
    solve(1, 0);
    cout<<*max_element(begin(maxdiam), end(maxdiam));
    return 0;
}