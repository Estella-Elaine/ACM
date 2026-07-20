struct DSU {
	vector<int> te, d;
	DSU(int n): te(n), d(n, 0) { iota(all(te), 0); }
 
	int find(int u) {
		if (u == te[u]) return u;
		int x = find(te[u]);
		d[u] ^= d[te[u]];
		return te[u] = x;
	}
 
	int merge(int u, int v, int w) {
		if (find(u) == find(v)) {
			assert(w == (d[u] ^ d[v]));
			return te[u];
		}
		d[te[u]] = d[u] ^ d[v] ^ w;
		te[te[u]] = te[v];
		return te[v];
	}
};