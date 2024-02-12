#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll p7 = 1000000007;
const ll INF = 1e18 + 69;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    //
    int N, M, Q;
    cin >> N >> M >> Q;
    

    long long dist[N + 1][N + 1]; // dist[a][b] : dist from a to b;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    while(M--){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(Q--){
        int a, b;
        cin >> a >> b;
        cout << ((dist[a][b] == INF) ? -1 : dist[a][b]) << '\n';
    }

    return 0;
}