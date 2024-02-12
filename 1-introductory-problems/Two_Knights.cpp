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
    
    ull n; cin >> n;
    vector<ull> kpair(n+1, 0);
    kpair[0] = kpair[1] = 0;
    kpair[2] = 6;
    kpair[3] = 28;
    for(ull k=1; k<=n; k++)
    {
        if(k>=4)
        {
            // calculate knight(k) and print it
            // K(n) = K(n-1) + n(n-1)(2n-1) - 8n + 16
            // oh boy this was fun to derive
            kpair[k] = kpair[k-1] + k*(k-1)*(2*k-1) - 8*k + 16;
        }
        cout<<kpair[k]<<endl;                                                                                                                                                                                                                                                                                                                                                                                                  
    }
    return 0;
}