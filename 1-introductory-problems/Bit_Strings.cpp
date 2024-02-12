#include <bits/stdc++.h>
using namespace std;

#define base 1000000007
typedef unsigned int ui;

int main()
{
    ui n; cin>>n;
    ui ans = 1;
    for(ui i=0;i<n;i++)
    {
        ans = (ui)ans<<1;
        ans = (ui)ans%base;
    }
    cout<<ans<<endl;
    return 0;
}