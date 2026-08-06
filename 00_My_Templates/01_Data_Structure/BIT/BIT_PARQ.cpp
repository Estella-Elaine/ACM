#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
适用背景：
维护一个数组 a，支持：
1 x v     a[x] += v
2 l r     查询 sum[l, r]
这是最基础的树状数组。

常见应用：
动态维护前缀和
单点修改，区间求和
逆序对统计
扫描线辅助统计
频率数组维护
*/

struct BIT{ // 单点加, 区间查询 (BIT_Point_Add____Range_Query)
	int n;
	vector<ll> tr;
	
	BIT(int _n = 0): n(_n), tr(_n + 2) {} // 初始化

	// void init(int _n){ // 全局 bit 初始化才需要
	// 	n = _n;
	// 	tr.assign(n + 2, 0);
	// }

	void add(int x, ll v){ // 单点加
		for(; x <= n; x += x & -x) tr[x] += v;
	}

	ll query(int x){ // 单点查询: 查前缀和 a[1, x]
		ll ans = 0;
		for(; x >= 1; x -= x & -x) ans += tr[x];
		return ans;
	}
	
	ll query(int l, int r){ // 区间查询: 即区间和 query[x, y]
		return query(r) - query(l - 1);
	}
};
// BIT bit; // 全局 bit

void work(){
	int n, q;
	cin >> n >> q;

	BIT bit(n);

	for(int i = 1; i <= n; ++i){
		ll x;
		cin >> x;
		bit.add(i, x);
	}
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int x;
			ll v;
			cin >> x >> v;
			bit.add(x, v);
		}else{
			int l, r;
			cin >> l >> r;
			cout << bit.query(l, r) << '\n';
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