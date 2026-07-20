#include<bits/stdc++.h>
using namespace std;
using ll = long long; 

struct BIT{ //?
	int n;
	vector<ll> tree;
	
	//？初始化
	void init(int n_){
		n = n_;
		tree = vector<ll>(n+1);
	}
	
	//单点加
	void add(int x, ll v){
		for(int i=x; i<=n; i+=i&-i){
			tree[i] += v;
		}
	}
	
	//查前缀和 a[1, x]
	ll query(int x){
		ll ans = 0;
		for(int i=x; i>=1; i-=i&-i){
			ans += tree[i];
		}
		return ans;
	}
	
	//查询区间和 即 query[x, y]
	ll query(int x,int y){
		return query(y) - query(x-1);
	}
};

void work(){
	int n, q;
	cin >> n >> q;
	vector<ll> a(n+1); 
	
	BIT bit;
	bit.init(n+1); //初始化
	
	for(int i=1; i<=n; i++){
		cin >> a[i];
		bit.add(i, a[i]);
		bit.add(i+1, -a[i]);
		
	}
	
	for(int i=1; i<=q; i++){
		int op;
		cin >> op;
		if(op == 1){
			int l, r, x;
			cin >> l >> r >> x;
			bit.add(l, x);
			bit.add(r+1, -x);
		}
		else{
			int x;
			cin >> x;
			ll anss = bit.query(x);
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
3 2
1 2 3
1 1 3 0
2 2

2
*/