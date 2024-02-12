#include <bits/stdc++.h>
using namespace std;

int main()
{
    int max_count=0, count=0;
    char prev=0;
    string s;
    cin>>s;
    for(char c: s)
    {
        if(c == prev) count++;
        else
        {
            if(count>max_count) max_count = count;
            count=1;
        }
        prev = c;
    }
    if(count>max_count) max_count = count;
    cout<<max_count<<endl;
    return 0;
}