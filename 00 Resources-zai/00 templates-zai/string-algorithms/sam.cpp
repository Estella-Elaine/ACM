template<int C = 26> struct SAM {
	vector<array<int, C>> nxt;
	vector<int> fa, len;

	int node(int l) {
		nxt.emplace_back().fill(-1);
		fa.push_back(-1);
		len.push_back(l);
		return sz(nxt) - 1;
	}

	SAM() { node(0); } // reserve vectors here if too slow

	int split(int u, int c) {
		int v = nxt[u][c];
		if (len[v] == len[u] + 1) return v;
		int w = node(len[u] + 1);
		fa[w] = fa[v];
		nxt[w] = nxt[v];
		fa[v] = w;
		for (; u != -1 and nxt[u][c] == v; u = fa[u]) nxt[u][c] = w;
		return w;
	}

	int extend(int u, int c) {
		if (nxt[u][c] != -1) return split(u, c); 
		int v = node(len[u] + 1);
		for (; u != -1 and nxt[u][c] == -1; u = fa[u]) nxt[u][c] = v;
		fa[v] = u == -1 ? 0 : split(u, c);
		return v;
	}

	ll calc() {
		int n = sz(nxt);
        ll res = 0;
		folr(u, 1, n - 1) res += len[u] - len[fa[u]];
		return res;
	}
}; // modified version supporting general-sam
