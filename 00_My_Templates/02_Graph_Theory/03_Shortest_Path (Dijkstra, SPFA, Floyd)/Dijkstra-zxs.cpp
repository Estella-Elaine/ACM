#include<bits/stdc++.h>
//#define int long long
using namespace std;
using ll=long long;
const int inf = (1ll << 31) - 1;

//这段代码实现了经典的 Dijkstra 单源最短路（无向带权图），
//用优先队列按距离扩展节点，最终输出从 s 到 t 的最短距离
//（如果不可达则输出 inf 的数值）

struct o{
	ll v, w;	//u->v 边权w
};

void work(){
	int n, m, s;
	cin >> n >> m >> s; 
	
	vector<vector<o> > e(n+1);
	for(int i=0; i<m; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w}); //有向图存边
	}
	
	vector<int> dis(n+1, inf), vis(n+1, 0);
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({0, s});
	while(!pq.empty()){
		auto nod = pq.top();
		auto [d,u] = nod;	//存距离，节点 按距离排序
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto [v, w] : e[u]){
			if(dis[v] > dis[u]+w){	//如果s->u->v路径长度比原来要小，则更新，那么就加进来这条边
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}

	for(int i=1; i<=n; i++){
		cout << dis[i];
		if(i != n) cout << " ";
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
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

0 2 4 3
*/
