#include <bits/stdc++.h>
using namespace std;

#define base 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main()
{
    ull n; cin >> n;
    // largest k such that 10^k divides n! => Legendre's Formula
    ull count2 = 0, count5 = 0;
    ull count10 = 0;
    // calculate the smaller of e_2(n!) and e_5(n!)
    // complexity is O(log_2 n) + O(log_5 n)
    ull ter2 = 2, ter5 = 5;

    // Method 1 for finding e_2(n!)

    // for(ull i=1; n/ter2 >= 1ULL; i++)
    // {
    //     count2 += (ull)(n/ter2);
    //     ter2 *= 2;
    // }

    // Method 2 for e_2(n!)
    count2 = n - __builtin_popcount((unsigned int)n); // simply count the number of 2^i terms that compose n

    // e_5(n!)
    for(ull i=1; n/ter5 >= 1ULL; i++)
    {
        count5 += (ull)(n/ter5);
        ter5 *= 5;
    }
    cout<<count2<<" "<<count5<<endl;
    count10 = (count2<count5)? count2 : count5;
    cout<<count10<<endl;
    return 0;
}