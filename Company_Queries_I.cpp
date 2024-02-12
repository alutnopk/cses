#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

int n, q;
// vector<vector<int>> Tr;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // standard binary lift, no biggie
    cin >> n >> q;
    // Tr.resize(n+1);
    vector<vector<int>> ances(30, vector<int>(n+1, 0));
    for(int i=2; i<=n; i++){ cin >> ances[0][i]; }
    for(int i=1; i<30; i++)
        for(int j=1; j<=n; j++)
            ances[i][j] = ances[i-1][ances[i-1][j]];
    
    for(int x,k,y;q--;)
    {
        cin >> x >> k;
        y = x;
        for(int i=0; (1<<i)<=k; i++)
        {
            if(((1<<i)&k)==0) continue;
            y = ances[i][y];
        }
        cout << ((!y)?-1:y) << "\n";
    }
    return 0;
}