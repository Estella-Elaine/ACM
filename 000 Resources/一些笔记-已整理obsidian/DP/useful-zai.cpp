#include<bits/stdc++.h>
using namespace std;
using ll = long long; 

const ll inf = 1ll <<  60;

void work(){
	int n;
	cin >> n;
	ll sum = 0, dp1 = -inf, dp2 = -inf, dp3 = -inf;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		sum += x;
		if(i > 1) dp3 = max(dp3, dp2 + x*3);
		if(i > 0) dp2 = max(dp2, dp1 + x*2);
		dp1 = max(dp1, sum);
		
//		dp1 = max(dp1, sum);
//		if(i > 0) dp2 = max(dp2, dp1 + x*2);
//		if(i > 1) dp3 = max(dp3, dp2 + x*3);
		cout << "dp1: " << dp1 << " dp2: " << dp2 << " dp3: " << dp3 << '\n';
	}
	cout << dp3 << '\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
//	cin >> t;
	while(t--) work();	
}

/*
8
3 -1 4 -1 5 -9 2 6
34

6
2 -1 -100 50 1 2
150

3
1 2 3
14
*/
