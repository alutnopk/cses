#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using ll = long long int;
constexpr ll INF = static_cast<ll>(1e18);

struct Connection
{
    int to{};
    ll length{};
};

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n{}, m{};
    std::cin >> n >> m;
    std::vector<std::vector<Connection>> G(n, std::vector<Connection>{});

    for(int i{0}; i<m; i++)
    {
        int from{}, to{}; ll length{};
        std::cin >> from >> to >> length;
        from--, to--;
        G[from].emplace_back(to, length);
    }
    std::vector<ll> shortest_path(n, INF);
    std::multimap<ll, int> unfinished_nodes{};
    // mark node 0 as "discovered"
    shortest_path[0] = 0LL;
    unfinished_nodes.emplace(0LL, 0);

    for(;unfinished_nodes.size();)
    {
        // extract the discovered node with smallest label
        int current_node{ unfinished_nodes.begin()->second };
        assert(unfinished_nodes.begin()->first == shortest_path[current_node]);
        unfinished_nodes.erase(unfinished_nodes.begin());
        // this node is officially finished; all that remains is to mark its neighbors discovered
        for(auto& conn: G[current_node])
        {
            int neighbor_node{ conn.to };
            if(shortest_path[neighbor_node] > shortest_path[current_node] + conn.length)
            {
                unfinished_nodes.erase(shortest_path[neighbor_node]);
                shortest_path[neighbor_node] = shortest_path[current_node] + conn.length;
                unfinished_nodes.emplace(shortest_path[neighbor_node], neighbor_node);
            }
        }
    }

    for(int i{0}; i<n; i++)
        std::cout << shortest_path[i] << " ";
    return 0;
}