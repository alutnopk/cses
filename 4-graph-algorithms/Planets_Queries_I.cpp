#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

int n, q;
vector<vector<int>> suc;


int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // successor graph, can use a sparse matrix with binary jumping
    cin >> n >> q;
    suc.assign(30, vector<int>(n+1));
    // suc[i][j] is the 2^i'th successor of planet j
    for(int i=1; i<=n; i++) cin >> suc[0][i];
    // populate suc
    for(int i=1; i<30; i++) // for each jump size
        for(int j=1; j<=n; j++) // for each planet
            suc[i][j] = suc[i-1][suc[i-1][j]];
            
    for(;q--;)
    {
        int x,k; cin >> x >> k;
        // use binary summation of k to decide series of jumps
        for(int i=0;(1<<i)<=k;i++)
            if(k&(1<<i)) x = suc[i][x];
        cout<<x<<"\n";
    }
    return 0;
}