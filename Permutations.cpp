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
    if(n == 1){ cout<<1<<endl; return 0; }
    if(n == 2 || n == 3){ cout<<"NO SOLUTION"<<endl; return 0; }
    // 2 4 1 3
    // 4 2 5 3 1
    // 2 4 6 1 3 5
    // 6 4 2 7 5 3 1
    // 2 4 6 8 1 3 5 7
    if(n%2 == 0)
    {
        for(int i=2; i<=n; i+=2) cout << i << " ";
        for(int i=1; i<n; i+=2) cout << i << " ";
        cout<<endl;
    }
    else
    {
        for(int i=n-1; i>=2; i-=2) cout << i << " ";
        for(int i=n; i>=1; i-=2) cout << i << " ";
        cout<<endl;
    }
    return 0;
}