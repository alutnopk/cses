#include <bits/stdc++.h>
#pragma GCC target ("arch=sandybridge")
using namespace std;

#define p7 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int dcount = 0, prev = 0;
    for(int &x: v)
    {
        if(x != prev) { dcount++; prev = x; }
        else continue;
    }
    cout<<dcount<<endl;
    return 0;
}