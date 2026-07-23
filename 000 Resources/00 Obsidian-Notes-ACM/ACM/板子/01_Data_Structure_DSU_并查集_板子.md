### 01_Data_Structure_DSU_并查集_板子
##### 并查集-板子
精简版：
```cpp
struct DSU{
	vector<int> te, sz;	// team
	DSU(int n): te(n){iota(all(te), 0);}
	int find(int u){return u == te[u] ? u : te[u] = find(te[u]);}
};
DSU U(n);
if(U.find(u) != U.find(v)) U.te[U.te[u]] = U.te[v];
```

全面版（含sz，unity）：
```cpp
struct DSU{
	vector<int> te, sz;	// team
	DSU(int n): te(n), sz(n, 1){iota(all(te), 0);}
	int find(int u){return u == te[u] ? u : te[u] = find(te[u]);}
	bool unity(int u, int v){ return(u = find(u)) == (v = find(v)) ? 0 : ((te[u] = v), sz[v] += sz[u], 1);}
};
//兼顾了动态开点、按秩（大小）合并、路径压缩、连通块大小统计、环判定
```