#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

vector<vector<int>> gray(1<<16, vector<int>(1<<4, 0));
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=(1<<(i-1)); j<(1<<i); j++)
        {
            // assign new column of one's
            gray[j][n-i] = 1;
            // mirror two grids
            for(int k=1;k<i;k++)
                gray[j][n-k] = gray[(1<<i)-1-j][n-k];
        }
    }
    for(int i=0; i<(1<<n); i++)
    {
        for(int j=0; j<n; j++) cout<<gray[i][j];
        cout<<endl;
    }
    return 0;
}