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
    
    ll n; cin >> n;
    vector<ll> v(n);
    ll maxsum=0, partialsum=0;
    for(ll i=0; i<n; i++)
    {
        cin >> v[i];
        partialsum = (partialsum < 0)? v[i]: v[i]+partialsum;
        if(i==0) maxsum = partialsum;
        maxsum = (partialsum > maxsum)? partialsum: maxsum;
    }
    maxsum = (partialsum > maxsum)? partialsum: maxsum;
    cout<<maxsum<<endl;
    return 0;
}