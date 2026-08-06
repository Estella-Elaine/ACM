#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
适用背景：
维护一个数组 a，支持：
1 l r v   a[l, r] += v
2 l r     查询 sum[l, r]
这个功能比前两个都强，用两个 BIT 维护。

核心公式：
设差分数组为 d。
a[1] + a[2] + ... + a[x]
= Σ d[i] * (x - i + 1)
= (x + 1) * Σd[i] - Σd[i] * i
所以维护两个树状数组：
s1 维护 d[i]
s2 维护 d[i] * i
前缀和：sum(x) = (x + 1) * s1.query(x) - s2.query(x)
*/

struct BIT{ // 区间加, 区间查询 (BIT_Range_Add___Range_Query)
	int n;
	vector<ll> tr;

	BIT(int _n = 0): n(_n), tr(_n + 2) {}

	void add(int x, ll v){ // 单点加
		for(; x <= n; x += x & -x) tr[x] += v;
	}

	ll query(int x){ // 单点查询: 查前缀和 a[1, x]
		ll ans = 0;
		for(; x >= 1; x -= x & -x) ans += tr[x];
		return ans;
	}
};

struct RBIT{
	int n;
	BIT s1, s2; // 用两个树状数组维护 "区间加、区间查" 功能

	RBIT(int _n): n(_n), s1(_n), s2(_n) {}

	void add(int x, ll v){
		s1.add(x, v), s2.add(x, v * x); // 两次单点加
	}

	void add(int l, int r, ll v){
		add(l, v), add(r + 1, -v); // 两次单点查询
	}

	ll query(int x){
		return (x + 1) * s1.query(x) - s2.query(x);
	}

	ll query(int l, int r){
		return query(r) - query(l - 1);
	}
};

void work(){
	int n, q;
	cin >> n >> q;

	RBIT bit(n);

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