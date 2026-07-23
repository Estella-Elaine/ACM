### 02_Graph_Theory_MST 最小生成树-板子
##### 最小生成树-板子
[P3366 【模板】最小生成树 - 洛谷](https://www.luogu.com.cn/problem/P3366)
```cpp
#include<bits/stdc++.h>
using namespace std;
//int dp[20][20];
const int N=1e5+5,M=2e5+5;
int par[5005];
int n,m;

struct o{
	int a,b,w;

	bool operator< (const o& e) const{
		return w<e.w;
	}
}e[M];

int Find(int x){
	if(par[x]==x){
		return x;
	}
	else{
		return par[x]=Find(par[x]);
	}
}

int tree(){
	sort(e,e+m);
//	sort(e, e + m);
	for(int i=0;i<=n;i++){
		par[i]=i;
	}
	int sum=0,cnt=0;
	for(int i=0;i<m;i++){
		int a=e[i].a,b=e[i].b,w=e[i].w;
		int roota=Find(a),rootb=Find(b);
		if(roota!=rootb){
			par[roota]=rootb;
			sum+=w;
			cnt++;
		}
	}
	
	if(cnt<n-1) return -1;
	else return sum;
}

void work(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		e[i]={a,b,w};
	}
	int ans=tree();
	if(ans==-1) cout<<"orz\n";
	else cout<<ans<<'\n';
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
//	cin>>t;
	while(t--){
		work();
	}
	return 0;
} 
```