template<int C = 26> struct PAM {
	vector<array<int, C>> nxt;
	vector<int> fa, len, dis;

	int node(int nfa, int nlen) {
		nxt.emplace_back().fill(0);
		fa.push_back(nfa);
		len.push_back(nlen);
		dis.push_back(0);
		return sz(nxt) - 1;
	}

	PAM() { node(1, 0); node(0, -1); }

	void build(string s) {
		auto find = [&](int u, int i) {
			while (i - len[u] - 1 < 0 or s[i - len[u] - 1] != s[i]) u = fa[u];
			return u;
		};
		int n = sz(s), u = 0, res = 0;
		folr(i, 0, n - 1) {
			int c = s[i] = (s[i] - 97 + res) % 26;
			u = find(u, i);
			if (!nxt[u][c]) {
				int v = nxt[u][c] = node(nxt[find(fa[u], i)][c], len[u] + 2);
				dis[v] = dis[fa[v]] + 1;
			}
			u = nxt[u][c];
			cout << (res = dis[u]) << ' ';
		}
		cout << '\n';
	}
};
