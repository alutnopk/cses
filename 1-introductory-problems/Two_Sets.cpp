#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n; cin >> n;
    ll total = (n*(n+1))/2;
    if(total%2){ cout<<"NO"<<endl; return 0; }
    cout<<"YES"<<endl;
    vector<bool> grp(n+1, false);
    ll sum = 0, half = total/2;
    int co = 0;
    for(int i=n; i>=1; i--)
    {
        if(sum+i<=half){ grp[i]=true; sum+=i; co++; }
        else { if(sum<half){grp[half-sum]=true; co++;} break; }
    }
    // first set
    cout<<co<<endl;
    for(int i=1; i<=n; i++) if(grp[i]) cout<<i<<" "; cout<<endl;
    // second set
    cout<<(n-co)<<endl;
    for(int i=1; i<=n; i++) if(!grp[i]) cout<<i<<" "; cout<<endl;
    return 0;
}