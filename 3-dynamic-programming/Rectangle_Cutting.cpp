#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

vector<vector<int>> memo;

int solve(int i, int j)
{
    if(memo[i][j]!=-1) return memo[i][j];

    if(i==j) memo[i][j]=0;
    else
    {
        int mincut=i*j, limi, limj;
        limi = (i-1)/2 + ((i-1)%2!=0);
        limj = (j-1)/2 + ((j-1)%2!=0);
        for(int k=1;k<=limi; k++)
        {
            mincut = min(mincut, 1+solve(k, j)+solve(i-k, j));
        }
        for(int k=1;k<=limj; k++)
        {
            mincut = min(mincut, 1+solve(i, k)+solve(i, j-k));
        }
        memo[i][j] = mincut;
    }
    // memo[i][j] = 1+solve(i-j, j);
    // else memo[i][j] = 1+solve(i, j-i);

    return memo[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b; cin >> a >> b;
    memo = vector<vector<int>>(a+1, vector<int>(b+1, -1));

    cout<<solve(a, b)<<endl;
    return 0;
}