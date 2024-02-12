#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll p7 = 1000000007;

int n, m;
vector<string> grid;
queue<array<int,2>> q;
vector<vector<int>> Mdist, Adist, bktrk;
vector<array<int,2>> B, mons, d;
array<int,2> A;
// path[][][0] is distance, path[][][1] is direction
// carefully scan for bugs

// bool newnbr(array<int,2>& v)
// {
//     return (v[0]>=0 && v[0]<n && v[1]>=0 && v[1]<m && grid[v[0]][v[1]]!='#' && path[v[0]][v[1]][0]==-1);
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    grid.resize(n);
    Adist.assign(n,vector<int>(m,-1)); bktrk.assign(n,vector<int>(m,-1));
    d.assign({{1,0},{0,1},{-1,0},{0,-1}});
    for(int i=0; i<n; i++)
    {
        cin >> grid[i];
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]=='#') continue;
            if(i==0||i==n-1||j==0||j==m-1) B.push_back({i,j});
            switch(grid[i][j])
            {
                case 'M': mons.push_back({i,j}); break;
                case 'A': A = {i,j}; break;
            }
        }
    }
    // start a BFS from THE ONE monster
    Mdist.assign(n,vector<int>(m,p7));
    for(;q.size();) q.pop();
    for(auto mon: mons) { Mdist[mon[0]][mon[1]] = 0; q.push(mon); }
    for(;q.size();)
    {
        auto u = q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            auto del = d[i];
            array<int,2> v = {u[0]+del[0], u[1]+del[1]};
            if(v[0]>=0 && v[0]<n && v[1]>=0 && v[1]<m && grid[v[0]][v[1]]!='#' && Mdist[v[0]][v[1]]==p7) // for each unvisited neighbor
            {
                // if unvisited, continue BFS
                Mdist[v[0]][v[1]] = 1 + Mdist[u[0]][u[1]];
                // 0 down, 1 right, 2 up, 3 left
                q.push(v);
            }
        }
    }
    // Do another DFS from A
    Adist.assign(n,vector<int>(m,p7)); bktrk.assign(n,vector<int>(m,-1));
    for(;q.size();) q.pop();
    Adist[A[0]][A[1]] = 0; bktrk[A[0]][A[1]] = -2;
    q.push(A);
    for(;q.size();)
    {
        auto u = q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            auto del = d[i];
            array<int,2> v = {u[0]+del[0], u[1]+del[1]};
            if(v[0]>=0 && v[0]<n && v[1]>=0 && v[1]<m && grid[v[0]][v[1]]!='#' && Adist[v[0]][v[1]]==p7) // for each unvisited neighbor
            {
                // if unvisited, continue BFS
                Adist[v[0]][v[1]] = 1 + Adist[u[0]][u[1]];
                bktrk[v[0]][v[1]] = i;
                // 0 down, 1 right, 2 up, 3 left
                q.push(v);
            }
        }
    }
    // at each exit, compare shortest path from A and from THE monster
    for(auto b: B)
    {
        if(Mdist[b[0]][b[1]] <= Adist[b[0]][b[1]]) continue; // nop
        else // bingo
        {
            cout<<"YES"<<endl;
            string ans;
            for(auto t=b;t!=A;)
            {
                int prev = bktrk[t[0]][t[1]];
                switch(prev)
                {
                    case 0: // down
                    ans.push_back('D'); t = {t[0]-1,t[1]}; break;
                    case 1: // right
                    ans.push_back('R'); t = {t[0],t[1]-1}; break;
                    case 2: // up
                    ans.push_back('U'); t = {t[0]+1,t[1]}; break;
                    case 3: // left
                    ans.push_back('L'); t = {t[0],t[1]+1}; break;
                }
            }
            cout<<ans.size()<<"\n";
            for(auto it=ans.rbegin(); it!=ans.rend(); it++) cout<<*it;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}