### 01_Data_Structure_SegTree_线段树_板子
[P3374 【模板】树状数组 1 - 洛谷](https://www.luogu.com.cn/problem/P3374)
```cpp
#include<bits/stdc++.h>
#define lp (p << 1)
#define rp (p << 1 | 1) //?等效于 #define rp (p << 1 + 1)
using namespace std;
using ll = long long; 
constexpr int inf = 0x3f3f3f;

struct SegTree{ //?
	int n;
	vector<ll> a;
	vector<ll> sum;
	
	//构造，初始化函数
	void init(int n_){
		n = n_;
		sum = vector<ll>((n+1) << 2);
	}
	
	void init(int n_, vector<ll>& a_){
		n = n_;
		a = a_;
		sum = vector<ll>((n+1) << 2);
		build(1, 1, n);
	}
	
	void pull(int p){
		sum[p] = sum[lp] + sum[rp];
	}
	
	void build(int p, int l, int r){
		if(l == r){
			sum[p] = a[l];
			return;
		}
		int mid = (l+r) >> 1;
		
		build(lp, l, mid);
		build(rp, mid+1, r);
		pull(p);
	}
	
	//单点修改
	void update(int p, int l, int r, int x, ll v){
		if(l == r){
			sum[p] += v;
			return;
		}
		
		int mid = (l+r) >> 1;
		if(x <= mid) update(lp, l, mid, x, v);
		else update(rp, mid+1, r, x, v);
		pull(p);
	}
	
	//区间查询
	ll query(int p, int l, int r, int x, int y){
		if(x <= l && r <= y) return sum[p];
		
		ll ans = 0;
		int mid = (l+r) >> 1;
		
		if(x <= mid) ans += query(lp, l, mid, x, y);
		if(y >= mid+1) ans += query(rp, mid+1, r, x, y);
		
		return ans;
	}
	
	//相当于对外接口，调用更简便
	void update(int x, ll v){ update(1, 0, n, x, v);} //单点修改
	ll query(int L, int R){ return query(1, 0, n, L, R);} //区间查询
};

void work(){
	int n,q;
	cin >> n >> q;
	vector<ll> a(n+1);
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	SegTree sgt;
	sgt.init(n,a);
	
	vector<int> ans;
	for(int i=1; i<=q; i++){
		int op;
		cin >> op;
		if(op == 1){
			int x, k;
			cin >> x >> k;
			sgt.update(1, 1, n, x, k);
		}
		else if(op == 2){
			int x, y;
			cin  >> x >> y;
			ll anss = sgt.query(1, 1, n, x, y);
			cout << anss << '\n';
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
//	cin >> t;
	while(t--) work();	
}

/*
5 5
1 5 4 2 3
1 1 3
2 2 5
1 3 -1
1 4 2
2 1 4

14
16
*/
```
