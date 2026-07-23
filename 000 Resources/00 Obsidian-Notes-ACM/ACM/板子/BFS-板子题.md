### BFS-板子题
[C - Spread of Rumors](https://atcoder.jp/contests/awc0033/tasks/awc0033_c)
```cpp
#include<bits/stdc++.h>  
#define ll long long  
#define all(a) (a).begin(), (a).end()  
using namespace std;  
  
void work(){  
    int n, m, k, t;  
    cin >> n >> m >> k >> t;  
    vector<int> vis(n+1, 0);  
    queue<int> q;  
    int sum = 0;  
    for(int i=0; i<k; i++){  
        int st;  
        cin >> st;  
        if(!vis[st]){  
            vis[st] = 1;  
            q.push(st);  
            ++sum;  
        }  
    }  
	vector<vector<int> > g(n+1);  
	for(int i=0; i<m; i++){  
		int u, v;  
		cin >> u >> v;  
		g[u].push_back(v);  
		g[v].push_back(u);  
    }  
	vector<int> cnt(n+1, 0); //有多少学生已经知道了谎言  
	while(!q.empty()){ //异步的 BFS（发现一个进一个）  
		int u = q.front();  
		q.pop();  
		for(int v : g[u]){  
            if(!vis[v]){  
                ++cnt[v];  
                if(cnt[v] >= t){ // 只有当知道的朋友数量 >=t 时，才触发“学习”  
                    vis[v] = 1;  
                    ++sum;  
                    q.push(v);  
                }  
            }  
        }  
    }  
	cout << sum << '\n';  
}  
  
signed main(){  
    ios::sync_with_stdio(0);  
    cin.tie(0);  
    int T=1;  
//    cin >> T;  
    while(T--) work();  
}
```