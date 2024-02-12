#include <bits/stdc++.h>
#pragma GCC target ("arch=sandybridge")
using namespace std;

#define p7 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

ll josephus(ll n, ll r)
{
    if(n == 1) return 1;
    if(r <= n/2) return 2*r;
    else
    {
        if(n%2 == 0) return 2*josephus(n/2, r-n/2)-1;
        else
        {
            ll j = josephus(n/2+1, r-n/2);
            if (j == 1) j += n/2+1;
            return 2*j-3;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n; cin >> n;
    for(ll r=1; r<=n; r++)
    {
        cout<<josephus(n, r)<<" ";
    }
    return 0;
}