#include<bits/stdc++.h>
using namespace std;
using i64 = long long; 
using ui64 = unsigned long long; 
#define sz(a) int((a).size())
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
const int inf = (1 << 30);
const i64 INF = (1ll << 60);

/*
Dijkstra 单源最短路（无向带权图）
*/

void work(){
	int n, m, s, t;
	cin >> n >> m >> s >> t; 
	s--, t--;
	vector<vector<pii>> g(n);
	
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});//无向图
	}
	
	//仍用默认 max-heap，但把距离存成负数：q.emplace(-dist, node); 
	//这样 top 返回的负值最大的也就是原始 dist 最小的条目
	priority_queue<pair<i64, int>> q;	//存负边权, 点
	// priority_queue<pair<i64, int>, 
	// vector<pair<i64, int>>, greater<pair<i64, int>>> q;	//存边权, 点
	vector<i64> dis(n, INF);			//到达每个点时的最短路
	
	dis[s] = 0;	//起点为零
	q.emplace(0, s);
	while(sz(q)){
		auto [d, u] = q.top(); //存 距离负值-dist, 节点u
		q.pop();
		if(-d != dis[u]) continue; // 删除旧状态
		for(auto [v, w] : g[u]){
			if(dis[u] + w < dis[v]){ //如果s->u->v路径长度比原来要小，则更新，那么就加进来这条边
				dis[v] = dis[u] + w;
				q.emplace(-dis[v], v);
			}
		}
	}
	cout << dis[t];	//到达终点的 最短路径
} 

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T; 
	while(T--) work();
	return 0;
}

/*
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

0 2 4 3
*/
