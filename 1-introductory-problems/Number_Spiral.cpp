#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll maxy(int x, int y)
{
    if(x>y) return x;
    else return y;
}
inline ll minxy(int x, int y)
{
    if(x<y) return x;
    else return y;
}

int main()
{
    int t; cin>>t;
    for(;t--;)
    {
        ll y,x;
        cin>>x>>y;
        ll X=x-1, Y=y-1;
        ll n = maxy(X, Y);
        int cond = (X==n)*(n%2==0) + (Y==n)*(n%2==1);
        ll ans = (n*n+n+1) + (X!=Y)*(1-2*cond)*(n-minxy(X,Y));
        cout<<ans<<endl;
    }
    return 0;
}