#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int prev = -1;
    long long count=0;
    for(int i=0; i<n; i++)
    {
        int t; cin>>t;
        if(i==0) {prev=t; continue;}
        if(t>=prev) prev=t;
        else
        {
            count += prev-t;
            t = prev;
        }
    }
    cout<<count<<endl;
    return 0;
}

/*
nothing for elem1
if (x >= prev) good, prev = x
else {count++ and x = prev}
*/