// 来源：牛客 81801612
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1ll<<60;

void work(){
	int n;
	cin >> n;
	
	vector<vector<ll>> dist(n, vector<ll>(n, inf));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int w;
			cin >> w;
			if(w == -1){
				if(i == j) dist[i][j] = 0;
				else dist[i][j] = inf;
			}
			else{
				dist[i][j] = w;
			}
		}
	}
	
	// Floyd–Warshall
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			if(dist[i][k] == inf) continue; // 小优化：如果 i->k 不可达，跳过
			for(int j=0; j<n; j++){
				if(dist[k][j] == inf) continue;
				ll cand = dist[i][k] + dist[k][j]; //candidate
				if(cand < dist[i][j]) dist[i][j] = cand;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(dist[i][j] >= inf/2) cout << -1;
			else cout << dist[i][j];
			if(j+1 < n) cout << " ";
		}
		cout << '\n';
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T=1;
//	cin>>T;
	while(T--){
		work();
	}
}

/*
4
0 1 -1 -1
-1 0 1 -1
-1 -1 0 1
1 -1 -1 0

0 1 2 3
3 0 1 2
2 3 0 1
1 2 3 0
*/