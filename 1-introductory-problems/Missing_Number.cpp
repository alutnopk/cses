#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n; cin >> n;
    long long s = (long long)(n*(n+1)/2);
    for(long long i=0;i<n-1;i++)
    {
        long long m; cin>>m;
        s -= m;
    }
    cout<<s<<endl;
    return 0;
}