#include<bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long; 

void work(){
	int n, m;
	cin >> n >> m; 
	
	vector<set<int> > g(n+1);
	vector<vector<int> > adj(n+1, vector<int>(n+1, 0));
	
	for(int i=1; i<=m; i++){
		int x, y;
		cin >> x >> y;
		g[x].insert(y);
		g[y].insert(x);
		
		adj[x][y] = 1;
		adj[y][x] = 1;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout << adj[i][j] << " ";
		}
		cout << '\n';
	}
	
	for(int i=1; i<=n; i++){
		cout << g[i].size() << " ";
		for(auto y:g[i]){
			cout << y << " ";
		}
		cout << '\n';
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
5 5
1 2
2 3
3 5
1 3
3 4

0 1 1 0 0
1 0 1 0 0
1 1 0 1 1
0 0 1 0 0
0 0 1 0 0
2 2 3
2 1 3
4 1 2 4 5
1 3
1 3
*/