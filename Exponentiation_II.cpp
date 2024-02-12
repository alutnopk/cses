#include <bits/stdc++.h>
#pragma GCC target ("arch=sandybridge")
using namespace std;

#define p7 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main()
{
    ull n; cin >> n;
    while(n--)
    {
        ull a, b, c;
        cin >> a >> b >> c;
        // calculate b^c mod (p-1)
        ull exp = 1ULL;
        ull A = a, B = b, C = c;
        for(;C>0;)
        {
            if((C&1) == 1)
                exp = (exp*B)%(p7-1);
            C = C>>1;
            B = (B*B)%(p7-1);
        }
        // cout<<exp<<endl;
        // now find a^exp mod p
        ull res = 1ULL;
        for(;exp>0;)
        {
            if((exp&1) == 1)
                res = (res*A)%p7;
            exp = exp>>1;
            A = (A*A)%p7;
        }
        cout<<res<<endl;
    }
    return 0;
}