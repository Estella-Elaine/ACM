#include<bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long; 

void work(){
	int n;
	cin >> n;
	
	vector<set<int> > g(n+1);
	for(int i=1; i<n; i++){
		int x, y;
		cin >> x >> y;
		g[x].insert(y);
		g[y].insert(x);
	}
	
	vector<int> dep(n+1);
	auto dfs = [&](auto &&self, int x, int p) ->void {
		for(auto y:g[x]){
			if(y == p) continue;
			dep[y] = dep[x] + 1;
			self(self, y, x);
		}
	};
	
	dfs(dfs, 1, -1);
	int u = max_element(dep.begin(), dep.end()) - dep.begin();
	fill(dep.begin(), dep.end(), 0);
	
	dfs(dfs, u, -1);
//	int v=max_element(dep.begin(),dep.end())-dep.begin();
	
	int d = *max_element(dep.begin(), dep.end());
	
	cout<<d;
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

