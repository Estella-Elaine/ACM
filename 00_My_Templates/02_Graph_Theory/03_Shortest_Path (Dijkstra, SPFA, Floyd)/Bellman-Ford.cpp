#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf=1ll<<60;

struct Edge{
	int u,v,w;
};

void work(){
	int n, m;
	cin >> n >> m;
	vector<Edge> edg;
	edg.reserve(m*2+1);
	
	for(int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		if(w >= 0){
			edg.push_back({u, v, w});
			edg.push_back({v, u, w});
		}
		else edg.push_back({u, v, w});
	}
	
	vector<ll> dist(n+1, inf);
	dist[1] = 0;
	for(int i=0; i<n-1; i++){
		bool flag = 0;
		for(auto e : edg){
			if(dist[e.u] != inf && dist[e.u] + e.w < dist[e.v]){
				dist[e.v] = dist[e.u] + e.w;
				flag = 1;
			}
		}
		if(!flag) break; //如果没有松弛，就代表结束了
	}
	
	// 再次尝试松弛，若能松弛且起点可达，则存在从 1 可达的负环
	bool circle = 0;
	for(auto &e : edg){
		if(dist[e.u] != inf && dist[e.u] + e.w < dist[e.v]){
			circle = 1;
			break;
		}
	}
	
	cout << (circle ? "YES" : "NO")<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
	cin >> T;
	while(T--) work();
}

/*
2
3 4
1 2 2
1 3 4
2 3 1
3 1 -3
3 3
1 2 3
2 3 4
3 1 -8

NO
YES
*/