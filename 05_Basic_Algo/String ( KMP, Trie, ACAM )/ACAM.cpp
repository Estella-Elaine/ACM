#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+6; // 模式串个数上限
const int SZ=2e5+6; // Trie 树节点上限
int n,tot,pidx;// n:模式串数; tot:Trie节点总数; pidx:不同模式串的编号计数
vector<int> ans(N);// ans[i] 最终答案：第 i 个模式串的出现次数
vector<int> idx(N);// idx[i] 模式串原始编号 -> 在 Trie 中对应节点的编号
string s;
struct Node{
	int son[26];// 子节点指针，存储节点编号
	int fail; // 失配指针（最长后缀匹配）
	int idx;// 如果是模式串结尾，存储该模式串的编号（0 表示非结尾）
	int du; // 拓扑排序用的入度（fail 树中该节点有多少个儿子）
	int ans; // 该节点在文本串中被访问的次数
	void init(){// 初始化一个节点
		memset(son,0,sizeof(son));
		ans=fail=idx=du=0;
		return;
	}
}tr[SZ];// 节点池

void init(){// 初始化自动机（多组数据时调用）
	tot=pidx=0;
	for(int i=0;i<=tot;i++) tr[i].init();// 重置所有节点（当前 tot 为 0，实际只清根）
	return;
}

void insert(string &s,int &idx){// 向 Trie 树插入一个模式串 s，num 返回该模式串映射后的编号（处理重复串）
	int u=0;// 从根节点开始
	for(int i=0;i<s.size();i++){
		int v=s[i]-'a'; // 字符转换成 0~25
		int &son=tr[u].son[v];// 引用，方便修改
		if(!son) son=++tot,tr[son].init();// 若无此子节点，新建  并初始化新节点
		u=son;
	}
	if(!tr[u].idx) tr[u].idx=++pidx; // 该节点首次被作为模式串结尾，分配新编号
	idx=tr[u].idx;// 返回映射后的编号（相同串共享编号）
	return;
}

void buildfail(){// 构建失配指针（fail 指针）并补全转移边（Trie 图）
	queue<int> q;
	for(int i=0;i<26;i++){  // 初始化：将根节点的所有存在的子节点入队
		if(tr[0].son[i]) q.push(tr[0].son[i]);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int v=tr[u].son[i]; // 当前子节点
			int f=tr[u].fail;// 当前节点的 fail
			if(v){
				tr[v].fail=tr[f].son[i];// 子节点的 fail 指向父节点 fail 的同字符儿子
				tr[tr[f].son[i]].du++;// 建 fail 树，增加入度（用于拓扑排序）
				q.push(v);
			}else tr[u].son[i]=tr[f].son[i]; // 子节点不存在，直接将转移边指向 fail 的对应儿子（路径压缩）
		}
	}
	return;
}

void query(string &s){// 用文本串 s 在自动机上运行，累加每个节点的访问次数
	int u=0;
	for(int i=0;i<s.size();i++){
		int v=s[i]-'a';
		u=tr[u].son[v];
		tr[u].ans++;
	}
	return;
}

void topu(){// 拓扑排序（按 fail 树自底向上累加 ans，得到每个模式串的出现次数）
	queue<int> q;
	for(int i=0;i<=tot;i++){
		if(tr[i].du==0) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans[tr[u].idx]=tr[u].ans; // 如果 u 是某个模式串的结尾，记录答案
		int v=tr[u].fail;
		tr[v].ans+=tr[u].ans; // 将当前节点的访问次数传递给 fail 节点
		if(!--tr[v].du) q.push(v);
	}
	return;
}
void solve(){
	init();// 初始化
	cin>>n;
	fill(ans.begin(), ans.begin() + n + 1, 0); // 清零答案数组和映射数组（只清到 n）
	fill(idx.begin(), idx.begin() + n + 1, 0);
	for(int i=1;i<=n;i++){
		string t;
		cin>>t;
		insert(t,idx[i]);
		ans[i]=0;
	}
	buildfail();
	string s;
	cin>>s;
	query(s);
	topu();
	for(int i=1;i<=n;i++) cout<<ans[idx[i]]<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T=1;
	//cin>>T;
	while(T--) solve();
}
