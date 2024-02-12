#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int p7 = 1000000007;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

#define NMX 200000

ll flog[NMX+1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, q; cin >> n >> q;
	vector<ll> X(n);
	for(int i=0; i<n; i++) cin >> X[i];
	// pre-compute floor(log2)
	flog[1] = 0;
	for(int i=2; i<=n; i++) flog[i] = flog[i/2]+1;
	// create power-of-2 sparse table to store sums
	vector<vector<ll>> ST(1+flog[n], vector<ll>(n, -1));
	// first row
	for(int j=0; j<n; j++) ST[0][j] = X[j];
	// subsequent rows
	for(int i=1; (1<<i)<=n; i++)
	{
		for(int j=0; j<=n-(1<<i); j++)
		{
			// ST[i][j] is the 2^i sized interval from element j
			ST[i][j] = ST[i-1][j] + ST[i-1][j+(1<<(i-1))];
		}
	}
	// process queries
	for(int i=0,a,b; i<q; i++)
	{
		cin >> a >> b; a--, b--;
		ll ans = 0;
		// split [a,b] interval into powers of 2, add it to sum variable
		int t = b-a+1;
		for(int k=0,strt=a;t>0;t>>=1,k++)
		{
			if(t&1)
			{
				ans += ST[k][strt];
				strt += (1<<k);
				// suppose 2^k is the window size i.e. the position we are in the binary number
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}