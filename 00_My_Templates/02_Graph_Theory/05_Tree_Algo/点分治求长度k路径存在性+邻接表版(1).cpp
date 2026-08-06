//洛谷P3806 
#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define K 10000005
int n,m;
struct node{
	int v,w;
}; 
vector<vector<node> >mat; //邻接表 
bool exist[K]; //判断差是否存在 
vector<int> dis,tmp,vis,siz; 
//非当前子树的可能距离 
//当前子树的可能距离
//是否进行过分治
//子树大小 
int cnt,cntt;
//dis,tmp的存储遍历下标 
int tis[105],ans[105];
//离线询问，统一处理 


//求子树大小 
inline void dfs1(int u,int fa){
	siz[u] = 1;
	for(auto it : mat[u]){
		int v = it.v;
		if(vis[v] || v == fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v]; 
	}
	return;
}

//求重心
inline void dfs2(int u,int fa,int root,int &minn,int &g){
	int maxn = siz[root]-siz[u]; //父亲方向子树大小 
	for(auto it : mat[u]){ //孩子方向子树大小 
		int v = it.v; 
		if(vis[v]||v==fa) continue;
		maxn = max(maxn,siz[v]);
		dfs2(v,u,root,minn,g);
	}
	if(maxn<minn) minn = maxn,g = u; //更新重心 
} 

//求与根的直线距离
inline void dfs3(int u,int fa,int dep){
	if(dep <= 1e7) tmp[++cntt] = dep;
	for(auto it:mat[u]){
		int v = it.v;
		int w = it.w;
		if(vis[v] || v==fa) continue;
		dfs3(v,u,dep+w);
	}
	return ;
} 

//递归分治
inline void dfz(int u){
	cnt = 0,cntt = 0;
	int minn = 1e9+7;
	int g;
	dfs1(u,0); //算子树大小 
	dfs2(u,0,u,minn,g); //找当前重心 
	vis[g] = 1;  //标记 
	//加入自环
	exist[0] = true; 
	dis[++cnt] = 0;
	
	for(auto it : mat[g]){ //遍历重心的每一个子树 
		int v = it.v;
		int w = it.w;
		if(vis[v]) continue; 
		cntt = 0;  //清0上一次的计算 
		dfs3(v,g,w); //获取该子树上每点到重心的距离 
		//遍历每一个距离，判断 询问-距离（差） 是否在其他子树中出现了 
		for(int i=1;i<=cntt;i++){  
			for(int j=1;j<=m;j++){ 
				//>=0防越界 
				if(tis[j]-tmp[i]>=0 && exist[tis[j]-tmp[i]]) ans[j] = 1;
			}
		}
		for(int i=1;i<=cntt;i++){ 
			//将当前子树的距离加入非当前子树的距离数组中
			//同时更新其存在性 
			dis[++cnt] = tmp[i];
			if(tmp[i]<=1e7) exist[tmp[i]] = true;
		}
	}
	//删除当前重心获得的所有边的存在性
	//不用assign是因为assign开销是N,大部分情况下远大于cnt 
	for(int i=1;i<=cnt;i++){
		if(dis[i]<=1e7) exist[dis[i]] = false;
	}
	//处理重心的所有子树
	//以他们的重心再分治 
	for(auto it : mat[g]){
		int v = it.v;
		if(!vis[v]) dfz(v);
	}
} 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	mat.assign(n+1,vector<node> (0));
	siz.assign(n+1,0);
	vis.assign(n+1,0);
	dis.assign(N,0);
	tmp.assign(N,0);
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mat[u].push_back({v,w});
		mat[v].push_back({u,w});
	}
	for(int i=1;i<=m;i++) cin>>tis[i];
	dfz(1);
	for(int i=1;i<=m;i++) cout<<(ans[i]?"AYE\n":"NAY\n");
}

//一些可能的疑问：
/*
1，为什么dfs1在每次求重心时都调用了，依然能用siz算出重心而没有数据污染？
	dif1中siz[u] 重置为 1了，相当于在外面siz.assign(N,1)了
	但assign开销大，dfs不会遍历整棵树
2，为什么dfs2要递归
	问出这个问题我建议你先去复习重心的求法
	重心本质是dfs遍历每一个点
	对与每一个点，获取删除该点后形成的子树中最大的那个
	而最大值最小的那个点就是重心
3，为什么分治过的点在dfs1，2，3中不处理
	这是点分治的核心
	vis数组会标记用来分治过的点
	同时，因为整个图是树形结构
	vis过的点可以分割这棵树
	相当与一个点一旦被分治过就从图上删除了
	而删除这个点会形成若干子树
	这与dfs1,2,3求的是子树相关量的逻辑不谋而合
	也就是说，vis防止dfs过程中访问了其他区块的内容
4，为什么要求重心
	dfs1,2,3会访问一整个区域
	如果图为链
	点分治只能一个一个删点
	dfs1,2,3就会进行大量的重复运算导致超时 
*/ 
