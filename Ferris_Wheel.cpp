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
    
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(int i=0; i<n; i++) { cin >> v[i]; }
    
    sort(v.begin(), v.end());
    // use a left and right pointer
    int l = 0, r = n-1;
    int count = 0;
    
    for(;v[r]>=x;r--)
    {
        if(v[r]>x) continue; // ignore oversized fellas
        else count++; // 1 gondola for each x
    }

    for(;l<=r;)
    {
        if(v[l]+v[r]<=x) l++; // best pair for a gondola found (least internal fragmentation)
        count++; r--; // big boi can't get a smaller gondola, so stay alone and go next
    }
    cout<<count<<endl;
    return 0;
}