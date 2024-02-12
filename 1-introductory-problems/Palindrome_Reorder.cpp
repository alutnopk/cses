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
    int n = s.size();
    vector<int> alpha(26, 0);
    for(char ch: s) alpha[ch-'A']++;
    string palin = "", mid = "";
    int oddC = 0;
    for(int i=0; i<26; i++)
    {
        if(alpha[i]%2)
        {
            oddC++;
            for(int j=0; j<alpha[i]; j++) mid.push_back((char)(i+'A'));
        }
        else
        {
            for(int j=0; j<alpha[i]/2; j++) palin.push_back((char)(i+'A'));
        }
    }
    if(n%2!=oddC)
    {
        cout<<"NO SOLUTION"<<endl; return 0;
    }

    cout<<palin<<mid;
    for(auto it=palin.rbegin(); it!=palin.rend(); it++) cout<<(*it);
    return 0;
}