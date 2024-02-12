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

#define N 1000000
int sumn[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    // compositions from 1 to 6
    sumn[0] = 0;
    for(int i=1; i<=6; i++)
    {
        sumn[i] = 1<<(i-1);
    }
    for(int i=7; i<=n; i++)
    {
        for(int j=1; j<=6; j++)
        {
            sumn[i] += sumn[i-j]%p7;
            sumn[i] %= p7;
        }
    }
    cout<<sumn[n]<<endl;
    return 0;
}