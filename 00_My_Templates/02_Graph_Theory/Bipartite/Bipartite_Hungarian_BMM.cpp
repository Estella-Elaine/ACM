#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
using ull = unsigned long long; 
#define sz(a) int((a).size())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) (a).begin(), (a).end()
const int inf = (1 << 30);
const ll INF = (1ll << 60);
const double PI = acos(-1);

void work(){
	int n, m, e;
	cin >> n >> m >> e;

	vector<vector<int>> g(n + 1);
	for(int i = 1; i <= e; ++i){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	vector<int> mc(m + 1);
	vector<int> vis(m + 1);
	int ans = 0;

	auto dfs = [&](auto&& self, int u) -> bool {
		for(auto v : g[u]){
			if(vis[v]) continue;
			vis[v] = true;
			if(!mc[v] || self(self, mc[v])){
				mc[v] = u;
				return true;
			}
		}
		return false;
	};

	for(int i = 1; i <= n; ++i){
		fill(all(vis), false);
		if(dfs(dfs, i)){
			++ans;
		}
	}

	cout << ans << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	work();
	return 0;
}