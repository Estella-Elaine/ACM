struct TwoSat {
	int n;
	vector<vector<int>> g;

	TwoSat(int n): n(n), g(n * 2) {}

	void add(int u, bool x, int v, bool y) { // u = x or v = y
		g[u << 1 | !x].push_back(v << 1 | y);
		g[v << 1 | !y].push_back(u << 1 | x);
	}

	vector<int> sat() {
		vector id(n * 2, -1), dfn(n * 2, - 1), low(n * 2, -1);
		vector<int> sta;
		int cnt = 0, scc = 0;
		function<void(int)> dfs = [&](int u) {
			low[u] = dfn[u] = cnt++;
			sta.push_back(u);
			for (int v : g[u]) {
				if (dfn[v] == -1) {
					dfs(v);
					low[u] = min(low[u], low[v]);
				} else if (id[v] == -1) low[u] = min(low[u], dfn[v]);
			}
			if (low[u] == dfn[u]) {
				while (true) {
					int v = sta.back();
					sta.pop_back();
					id[v] = scc;
					if (v == u) break;
				}
				++scc;
			}
		};
		folr(u, 0, n * 2 - 1) if (dfn[u] == -1) dfs(u);
		vector res(n, -1);
		folr(u, 0, n - 1) {
			if (id[u << 1] == id[u << 1 | 1]) return {};
			res[u] = id[u << 1] > id[u << 1 | 1];
		}
		return res;
	} // no answer: result = {}
};