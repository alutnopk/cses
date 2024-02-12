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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, int>> intervals;
    for(int i=0; i<n; i++)
    { 
        int a, b; cin >> a >> b;
        intervals.push_back({b, a});
    }
    sort(intervals.begin(), intervals.end());
    int maxc = 0, lastf = 0;
    for(int i=0; i<n; i++)
    {
        if(intervals[i].second >= lastf)
        {
            maxc++; lastf = intervals[i].first;
        }
    }
    cout<<maxc<<endl;
    return 0;
}