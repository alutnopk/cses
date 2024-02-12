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
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    
    // 45 60 60 80
    // 30 60 75
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    int ai = 0, bi = 0, count = 0;
    for(;ai<n && bi<m;)
    {
        if(a[ai] <= b[bi]+k)
        {
            if(a[ai] >= b[bi]-k) // can be allocated
            {
                count++; ai++; bi++;
            }
            else // reject applicant
            {
                ai++;
            }
        }
        else // bi too small, skip it
        {
            bi++;
        }
    }
    cout<<count<<endl;
    return 0;
}