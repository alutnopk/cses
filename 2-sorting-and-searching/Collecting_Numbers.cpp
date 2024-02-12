#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    // find the inverted index array
    vector<int> idx(n);
    for(int i=0; i<n; i++){ int x; cin >> x; x--; idx[x]=i; }
    int no_rounds = 1, prev = idx[0];
    for(int i=1; i<n; i++)
    {
        if(idx[i]<=prev) no_rounds++;
        prev = idx[i];
    }
    cout<<no_rounds;
    

    return 0;
}