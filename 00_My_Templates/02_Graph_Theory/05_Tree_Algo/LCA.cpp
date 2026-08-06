#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int bitN=20;			// 倍增最大位数，2^19 = 524288 适合 N ≤ 5e5
vector<vector<int> > g,fa;// g: 邻接表; fa[k][u]: u 向上跳 2^k 步的祖先
vector<int> dep;		// 每个结点的深度

void depth(int u,int par){
	fa[0][u]=par;		// 直接父亲
	dep[u]=dep[par]+1;	// 深度比父亲多 1
	for(int k=1;k<bitN;k++){
		fa[k][u]=fa[k-1][fa[k-1][u]];
	}
	for(auto v:g[u]){
		if(v==par) continue;// 避免走回父结点
		depth(v,u);
	}
}

int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v); // 保证 u 是深度较大的那个
	int diff=dep[u]-dep[v];
	for(int k=bitN-1;k>=0;k--){ // 将 u 向上提升至与 v 同一深度
		if(diff&(1<<k)) u=fa[k][u];
	}
	if(u==v) return u;			// v 原本就是 u 的祖先
	for(int k=bitN-1;k>=0;k--){// 一起向上跳，保持跳完后祖先不相等，最终停在 LCA 的儿子结点
		if(fa[k][u]!=fa[k][v]){
			u=fa[k][u];
			v=fa[k][v];
		}
	}
	return fa[0][u];
}
void solve(){
	int n,m,s;
	cin>>n>>m>>s;
	
	g.assign(n+1,vector<int>());
	dep.assign(n+1,0);
	fa.assign(bitN,vector<int>(n+1,0));
	fa[0][s]=0;// 根的父亲设为 0（虚结点）
	dep[0]=0;// 虚结点深度为 0，使根深度为 1
	
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	depth(s,0);// 从根开始 DFS 预处理
	
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		cout<<LCA(u,v)<<"\n";
	}
} 

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T=1;
	cin>>T;
	while(T--) solve();
}

