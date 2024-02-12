#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC target("arch=sandybridge")
using namespace std;
using namespace __gnu_pbds;

#define p7 1000000007
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

bool comp(int ticket, int maxticket)
{
    return (ticket <= maxticket);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // Courtesy: Prakhar
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    vector<int> t(m);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        h.insert(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }

    for (int g : t)
    {
        if (t.size() == 0)
            break;
        auto pos = h.lower_bound(g);
        // cout << g << "  " << *pos<<endl;
        if (*pos == g)
        {
            ans.push_back(*pos);
            h.erase(pos);
        }
        else
        {
            if (pos == h.begin())
            {
                ans.push_back(-1);
            }
            else
            {
                pos--;
                ans.push_back(*pos);
                h.erase(pos);
            }
        }
    }
    for (auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}