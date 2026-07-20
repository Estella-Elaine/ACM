#include<bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long; 

void work(){
	int n;
	cin >> n; 
	
	vector<int> d(n+1,0);
	vector<vector<int> > g(n+1);
	
	for(int i=1; i<=n; i++){
		int x;
		while(cin >> x){
			if(x == 0) break;
			d[x]++;
			g[i].push_back(x);
		}
		
	}
	
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(d[i] == 0)
			q.push(i);
	}
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << " ";
		for(auto y:g[x]){
			d[y]--;
			if(d[y] == 0){
				q.push(y);
			}
		}
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