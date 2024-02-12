#include <bits/stdc++.h>
#pragma GCC target ("arch=sandybridge")
using namespace std;

#define p7 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

ll josephus(ll n, ll r)
{
    if(n==1) return 1;
    if(r <= n/2) return 2*r; // obvious
    else // recursion with Josephus series of size n/2
    {
        if(n%2 == 0) return 2*josephus(n/2, r-n/2)-1;
        else
        {
            ll j = josephus(n/2+1, r-n/2);
            if(j==1) j += n/2+1; // when j=1, upper layer should be passed j+n; a gimmick because of circular assignment
            return 2*j-3;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ull T; cin >> T;
    while(T--)
    {
        ll n, r;
        cin >> n >> r;
        cout << josephus(n, r) << endl;
    }
    return 0;
}