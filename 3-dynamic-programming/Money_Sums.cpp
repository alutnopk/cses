#include <bits/stdc++.h>
using namespace std;

const int p7 = 1000000007;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

vector<int> x;
vector<vector<int>> memo;
vector<int> res;

// int solve(int i, int j)
// {
//     if(i<0) return 0;
//     if(memo[i][j]!=-1) return memo[i][j];
//     if(i!=0 && j==0) { memo[i][j] = 0; return 0; }
//     if(i==0 && j==0) { memo[i][j] = 1; return 1; }
//     memo[i][j] = (solve(i, j-1)+solve(i-x[j-1], j-1)>0);
//     if(memo[i][j]) res.push_back(i);
//     return memo[i][j];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int su = 0;
    x = vector<int>(n);
    for(int i=0; i<n; i++) { cin >> x[i]; su += x[i]; }
    // memo = vector<vector<int>>(su+1, vector<int>(n+1, -1));

    // sort(x.begin(), x.end());
    // solve(su, n);
    // for(int k: res) cout << k << " ";
    set<int> uniqsum;
    for(int i=0; i<n; i++)
    {
        set<int> cur; cur.clear();
        // add x[i]
        cur.insert(x[i]);
        for(int s: uniqsum)
        {
            cur.insert(s+x[i]);
        }
        uniqsum.insert(cur.begin(), cur.end());
    }
    cout<<uniqsum.size()<<endl;
    for(int s: uniqsum) cout<<s<<" ";
    
    return 0;
}