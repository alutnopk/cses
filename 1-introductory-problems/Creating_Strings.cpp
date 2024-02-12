#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin >> s;
    vector<string> res;
    sort(s.begin(), s.end());
    do
    {
        res.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    cout<<res.size()<<endl;
    for(string x: res) cout<<x<<endl;
    return 0;
}