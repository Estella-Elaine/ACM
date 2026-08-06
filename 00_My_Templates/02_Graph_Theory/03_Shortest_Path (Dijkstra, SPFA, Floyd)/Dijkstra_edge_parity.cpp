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
	int n, m, s, t;
	cin >> n >> m >> s >> t;

	vector<vector<pair<int, ll>>> g(n + 1);
	for(int i = 1; i <= m; ++i){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}

	using tp = tuple<ll, int, int>; // 状态为：距离、节点、经过边数的奇偶性
	priority_queue<tp, vector<tp>, greater<tp>> q;
	vector<array<ll, 2>> dis(n + 1, {INF, INF});

	dis[s][0] = 0; // 起点为偶数状态
	q.emplace(0, s, 0);

	while(!q.empty()){
		auto [d, u, p] = q.top();
		q.pop();
		if(d != dis[u][p]) continue; // 跳过已经过期的状态

		for(auto [v, w] : g[u]){
			int np = p ^ 1; // 每经过一条边，边数奇偶性翻转
			if(d + w < dis[v][np]){
				dis[v][np] = d + w;
				q.emplace(dis[v][np], v, np);
			}
		}
	}

	for(int p = 0; p < 2; ++p){ // 依次输出经过偶、奇数条边的最短距离
		if(dis[t][p] == INF) cout << -1;
		else cout << dis[t][p];
		cout << " \n"[p == 1];
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