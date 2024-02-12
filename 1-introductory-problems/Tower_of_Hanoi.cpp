#include <bits/stdc++.h>
#pragma GCC target ("arch=sandybridge")
using namespace std;

#define p7 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

inline int positive_modulo(int i, int n) {
    return (i % n) + ((i < 0)? n: 0);
}

void hanoi(int n, int src=0, int dest=2)
{
    if(n==0) return;
    int temp = positive_modulo(2*dest-src, 3);
    // move T(n-1) from 1 to 2
    hanoi(n-1, src, temp);
    // move last disk from 1 to 3
    cout<<src+1<<" "<<dest+1<<endl;
    // move T(n-1) from 2 to 3
    hanoi(n-1, temp, dest);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    // T(n) = 2^n - 1
    cout << (1<<n)-1 << endl;
    hanoi(n);
    return 0;
}