#include <iostream>
#include <vector>
#include <bit>

using lli = long long int;

template <typename T>
inline T addmod(T x, T y)
{
    const lli p7 = 1000000007;
    return (x % p7 + y % p7) % p7;
}

int N{}, M{};
std::vector<std::vector<int>> G{};
std::vector<std::vector<lli>> DP{};

lli foo(int u, uint32_t S)
{
    // DP fetch
    if (DP[u][S] != -1)
        return DP[u][S];
    // base case i.e. loop termination
    if (std::popcount(S) == N - 1) // if N-1 are traversed
    {
        return lli(G[u][N - 1]);
    }

    DP[u][S] = 0ll;
    for (int v = 0; v < N; v++)
    {
        if (!G[u][v] || v == N - 1 || S & (1U << v)) // if invalid neighbor or final node or selected node
            continue;
        DP[u][S] = addmod(DP[u][S], G[u][v] * foo(v, S | (1U << v)));
    }
    return DP[u][S];
}

int main()
{
    std::cin >> N >> M;

    G.assign(N, std::vector<int>(N, 0));
    DP.assign(N, std::vector<lli>(1U << (N - 1), -1));
    for (int i = 0; i < M; i++)
    {
        int a{}, b{};
        std::cin >> a >> b;
        G[a - 1][b - 1]++;
    }
    // realize that number of paths from node i to N-1, having selected set S already, is recomputed in brute force
    // recursion: f[i][S] = 0 + sum(f[j][S&{j}]) for j in nbr(i) and not in S
    // base case: f[u][011111.....1] = G[u][N-1]
    // entrypoint: f[0][1]
    std::cout << foo(0, (uint32_t)1) << std::endl;
    return 0;
}