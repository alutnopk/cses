#include <iostream>
#include <vector>
#include <algorithm>

constexpr int SENTINEL = 0;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    int n{};
    std::cin >> n;
    std::vector<int> DP{SENTINEL};

    for(int i{0}; i<n; i++)
    {
        int x{};
        std::cin >> x;
        // if x can expand LIS at the end
        if(x > DP.back())
            DP.emplace_back(x);
        else
        {
            int idx = std::upper_bound(DP.begin(), DP.end(), x) - DP.begin();
            if(DP[idx-1] != x) DP[idx] = x;
        }
    }
    std::cout << int(DP.size())-1 << std::endl;
    return 0;
}