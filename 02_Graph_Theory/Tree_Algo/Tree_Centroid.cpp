#include<bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long; 

void work(){
	int cen = -1;
	int ans = 1e9;
	
	int n;
	cin >> n;
	
	vector<set<int> > g(n+1);
	for(int i=1; i<n; i++){
		int x, y;
		cin >> x >> y;
		g[x].insert(y);
		g[y].insert(x);
	}
	
	vector<int> dep(n+1, 0), siz(n+1, 0);
	auto dfs = [&](auto &&self, int x, int p) ->int {
		siz[x] = 1;
		int con = 0;
		for(auto y:g[x]){
			if(y == p) continue;
			dep[y] = dep[x]+1;
			int sy = self(self, y, x);
			siz[x] += sy;
			con = max(con, sy);
		}
		con = max(con, n-siz[x]);
		
		if(con < ans){
			cen = x;
			ans = con;
		}
		else if(con == ans){
			cen = min(x,cen);
		}
		return siz[x];
	};
	
	dfs(dfs, 1, -1);
	
	siz.assign(n+1, 0);
	dep.assign(n+1, 0);
	
	dfs(dfs, cen, -1);
	
	int ssum = 0;
	for(int i=1; i<=n; i++){
		ssum += dep[i];
	}
	cout << cen << " " << ssum;
	
} 

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
//	cin >> T;
	while(T--){
		work();
	}
}
/*
*/