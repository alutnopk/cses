#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC target ("arch=sandybridge")
using namespace std;
using namespace __gnu_pbds;

#define p7 1000000007
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x; cin >> n >> x;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++)
    {
        int x; cin >> x;
        v.push_back({x, i+1});
    }
    
    sort(v.begin(), v.end());
    if(n==1){ cout<<"IMPOSSIBLE"<<endl; return 0; }
    if((x < v[0].f+v[1].f)||(x > v[n-2].f+v[n-1].f)){ cout<<"IMPOSSIBLE"<<endl; return 0; }
    int l = 0, r = n-1;
    for(;(l>=0) && (l<r) && (r<=n-1);)
    {
        int s = v[l].f + v[r].f;
        if(x==s){ cout<<v[l].s<<" "<<v[r].s; return 0; }
        else if(x > s) l++;
        else r--;
    }
    cout<<"IMPOSSIBLE"<<endl; return 0;
    return 0;
}