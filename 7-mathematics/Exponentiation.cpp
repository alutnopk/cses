#include <bits/stdc++.h>
using namespace std;

#define base 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main()
{
    ull n; cin >> n;
    while(n--)
    {
        ull a, b;
        cin >> a >> b;
        ull res = 1ULL;
        a = a%base;
        for(;b>0;)
        {
            if((b&1) == 1)
                res = (res*a)%base;
            b = b>>1;
            a = (a*a)%base;
        }
        cout<<res<<endl;
    }
    return 0;
}