#include<bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long; 

void work(){
	int n, m;
	cin >> n >> m; 
	
	vector<set<int> > g(n+1);
	for(int i=1; i<=m; i++){
		int x, y;
		cin >> x >> y;
		g[x].insert(y);
	}
	
	int ans = 0;
	vector<int> vis(n+1, 0);
	auto dfs = [&](auto &&self, int x) ->void {
		ans = max(ans, x);
		for(auto y:g[x]){
			if(vis[y]) continue;
			vis[y] = 1;
			self(self, y);
		}
	};
	
	for(int i=1; i<=n; i++){
		fill(vis.begin(), vis.end(), 0);
		ans = 0;
		dfs(dfs, i);
		cout << ans << " ";
	}

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