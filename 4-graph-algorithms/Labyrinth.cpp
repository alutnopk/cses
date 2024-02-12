#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int m, n;
char grid[1000][1000], direc[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> current_nodes;

bool new_nbr(int p, int q)
{
    return (p>=0 && p<=n-1 && q>=0 && q<=m-1 && grid[p][q]!='#' && dist[p][q]==100000000);
}
void update_nbr(int p, int q, char c)
{
    switch(c)
    {
        case 'U': dist[p][q] = dist[p+1][q] + 1; break;
        case 'D': dist[p][q] = dist[p-1][q] + 1; break;
        case 'L': dist[p][q] = dist[p][q+1] + 1; break;
        case 'R': dist[p][q] = dist[p][q-1] + 1; break;
    }
    direc[p][q] = c;
    current_nodes.push({p, q});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // accept inputs
    cin >> n >> m;
    int ax, ay, bx, by;
    ax = ay = bx = by = -1;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        for(int j=0; j<m; j++)
        {
            grid[i][j] = s[j];
            dist[i][j] = 100000000;
            if(s[j] == 'A')
            { ax=i; ay=j; }
            if(s[j] == 'B')
            { bx=i; by=j; }
        }
    }
    // bfs from ax, ay
    current_nodes.push({ax, ay});
    dist[ax][ay] = 0;
    while(!current_nodes.empty())
    {
        auto cn = current_nodes.front();
        int p = cn.first, q = cn.second;
        current_nodes.pop();
        if(p==bx && q==by) break;
        // process untraversed neighbors
        if(new_nbr(p-1, q)) update_nbr(p-1, q, 'U');
        if(new_nbr(p+1, q)) update_nbr(p+1, q, 'D');
        if(new_nbr(p, q-1)) update_nbr(p, q-1, 'L');
        if(new_nbr(p, q+1)) update_nbr(p, q+1, 'R');
    }
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //         cout<<dist[i][j]<<" ";
    //     cout<<endl;
    // }
    // follow the trail from bx, by
    if(dist[bx][by]==100000000)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES\n"<<dist[bx][by]<<endl;
        string rans;
        for(int p=bx, q=by;!(p==ax && q==ay);)
        {
            rans.push_back(direc[p][q]);
            // go to parent node
            switch(direc[p][q])
            {
                case 'U': p++; break;
                case 'D': p--; break;
                case 'L': q++; break;
                case 'R': q--; break;
            }
        }
        for(auto it=rans.rbegin(); it!=rans.rend(); it++)
        cout<<*it;
    }
    return 0;
}