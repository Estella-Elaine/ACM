#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
适用背景：
维护一个矩阵 a，支持：
单点加, 矩阵查询

常见应用：
二维前缀和动态版
矩阵单点修改，矩形求和
平面点统计
离线扫描二维偏序
*/

struct BIT2{
	int n, m;
	vector<vector<ll>> tr;

	BIT2(int _n, int _m): n(_n), m(_m), tr(n + 2, vector<ll>(m + 2)) {}

	void add(int x, int y, ll v){
		for(int i = x; i <= n; i += i & -i){
			for(int j = y; j <= m; j += j & -j){
				tr[i][j] += v;
			}
		}
	}

	ll query(int x, int y){
		ll ans = 0;
		for(int i = x; i >= 1; i -= i & -i){
			for(int j = y; j >= 1; j -= j & -j){
				ans += tr[i][j];
			}
		}
		return ans;
	}

	ll query(int x1, int y1, int x2, int y2){
		return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
	}
};

void work(){
	int n, m, q;
	cin >> n >> m >> q;

	BIT2 bit(n, m);

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			ll x;
			cin >> x;
			bit.add(i, j, x);
		}
	}

	while(q--){
		int op;
		cin >> op;

		if(op == 1){
			int x, y;
			ll v;
			cin >> x >> y >> v;
			bit.add(x, y, v);
		}else{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << bit.query(x1, y1, x2, y2) << '\n';
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while(T--) work();
	return 0;
}
