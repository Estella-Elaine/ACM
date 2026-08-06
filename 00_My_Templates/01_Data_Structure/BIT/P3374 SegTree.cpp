#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
//const int M=1e8;
// const int N = 1e6;
//ll c[M][M];
// ll ssum[N];
// ll n,m;

struct BIT{
	int n;
	vector<ll> ssum;
	BIT(int n) : n(n), ssum(n+1, 0) {}

	void add(int x, int v){
		for(int i=x; i<=n; i += i&-i){
			ssum[i] += v;
		}
	}

	ll query(int x){
		ll ans=0;
		for(int i=x; i>=1; i -= i&-i){
			ans += ssum[i];
		}
		return ans;
	}
};


void work(){
	int n, m;
	cin >> n >> m;
	BIT tree(n);
	vector<int> a(n+1);
	for(int i=1; i<=n; i++){
		cin >> a[i];
		tree.add(i, a[i]);
	}
	for(int i=0; i<m; i++){
		int op;
		cin >> op;
		if(op == 1){
			int x, k;
			cin >> x >> k;
			tree.add(x, k);
		}
		else if(op == 2){
			int x, y;
			cin >> x >> y;
			cout<< tree.query(y) - tree.query(x-1) << '\n';
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<ssum[i]<<" ";
//	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T = 1;
//	cin >> T;
	while(T--){
		work();
	}
}

/*
2
5 1001 
20 1001  

128
86
*/