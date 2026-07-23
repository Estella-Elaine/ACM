#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	int n,ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		ans *= i;
	}
	cout << n << "µÄ½×³ËÊÇ:" << ans << endl;
	return 0;
}

