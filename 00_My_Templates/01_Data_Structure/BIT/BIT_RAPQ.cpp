#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
适用背景：
维护一个数组 a，支持：
1 l r v   a[l, r] += v
2 x       查询 a[x]
核心思想是维护差分数组 d。

如果：a[i] = d[1] + d[2] + ... + d[i]
那么区间加：a[l, r] += v
等价于：d[l] += v	d[r + 1] -= v

常见应用：
区间整体加
最后查询某些点的值
离线区间覆盖统计
差分思想 + BIT 动态化
*/

struct BIT{ // 区间加, 单点查询 (BIT_Range_Add___Point_Query)
	int n;
	vector<ll> tr;
	
	BIT(int _n = 0): n(_n), tr(_n + 2) {} // 初始化

	void add(int x, ll v){ // 单点加
		for(; x <= n; x += x & -x) tr[x] += v;
	}

	void add(int l, int r, ll v){ // 区间加
		add(l, v);
		add(r + 1, -v);
	}

	ll query(int x){ // 单点查询: 查前缀和 a[1, x]
		ll ans = 0;
		for(; x >= 1; x -= x & -x) ans += tr[x];
		return ans;
	}
};

void work(){
	int n, q;
	cin >> n >> q;

	BIT bit(n);

	for(int i = 1; i <= n; ++i){
		ll x;
		cin >> x;
		bit.add(i, i, x);
	}

	while(q--){
		int op;
		cin >> op;

		if(op == 1){
			int l, r;
			ll v;
			cin >> l >> r >> v;
			bit.add(l, r, v);
		}else{
			int x;
			cin >> x;
			cout << bit.query(x) << '\n';
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