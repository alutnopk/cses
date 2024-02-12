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
    
    int T; cin >> T;
    while(T--)
    {
        int a, b; cin >> a >> b;
        bool flag = true;
        if(((2*b-a)%3 != 0) || ((2*a-b)%3 != 0)) flag = false;
        if((2*b < a) || (2*a < b)) flag = false;

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}