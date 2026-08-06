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
	int n;
	cin >> n;

	vector<vector<int>> g(n + 1);
	for(int i = 1; i <= n; ++i){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> deg(n + 1), inq(n + 1), cyc(n + 1);
	queue<int> q;

	for(int i = 1; i <= n; ++i){
		deg[i] = sz(g[i]);
		if(deg[i] == 1){
			q.push(i);
			inq[i] = true;
		}
	}

	// 拓扑删叶子，最后没被删掉的点就是环上的点
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(auto v : g[u]){
			if(inq[v]) continue;
			--deg[v];
			if(deg[v] == 1){
				inq[v] = true;
				q.push(v);
			}
		}
	}

	vector<int> ring;
	for(int i = 1; i <= n; ++i){
		if(!inq[i]){
			cyc[i] = true;
			ring.push_back(i);
		}
	}

	vector<int> rt(n + 1), dep(n + 1), fa(n + 1);
	auto dfs = [&](auto&& self, int u, int p, int r) -> void {
		rt[u] = r;
		fa[u] = p;
		for(auto v : g[u]){
			if(v == p || cyc[v]) continue;
			dep[v] = dep[u] + 1;
			self(self, v, u, r);
		}
	};

	for(auto x : ring){
		dep[x] = 0;
		dfs(dfs, x, 0, x);
	}

	// ring：所有环点
	// cyc[u]：u 是否在环上
	// rt[u]：u 所属的环点根
	// dep[u]：u 到所属环点的距离
	// fa[u]：树边父亲，环点父亲为 0

	cout << sz(ring) << '\n';
	for(auto x : ring){
		cout << x << " \n"[x == ring.back()];
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}