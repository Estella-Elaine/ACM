template<class Cap, Cap InfCap = numeric_limits<Cap>::max()>
struct Dinic {
	int n;
	vector<int> head, to, nxt, dis;
	vector<Cap> cap;

	Dinic(int n): n(n), head(n, -1) {} 

	void AddDir(int u, int v, Cap w) {
		nxt.push_back(head[u]);
		head[u] = sz(cap);
		to.push_back(v);
		cap.push_back(w);
	}

	void add(int u, int v, Cap w, bool dir = 1) {
		AddDir(u, v, w);
		AddDir(v, u, dir ? 0 : w);
	}

	Cap flow(int s, int t) {
		auto bfs = [&]() {
			dis.assign(n, -1);
			dis[t] = 0;
			vector q{t};
			folr(ind, 0, sz(q) - 1) {
				int u = q[ind];
				for (int i = head[u]; ~i; i = nxt[i]) if (cap[i ^ 1] and dis[to[i]] == -1) {
					dis[to[i]] = dis[u] + 1;
					q.push_back(to[i]);
					if (to[i] == s) return true;
				}
			}
			return false;
		};
		vector<int> cur;
		function<Cap(int, Cap)> dfs = [&](int u, Cap c) {
			if (u == t or !c) return c;
			Cap r = c, f;
			for (int& i = head[u]; ~i; i = nxt[i]) if (cap[i] and dis[to[i]] == dis[u] - 1 and (f = dfs(to[i], min(cap[i], r)))) {
				r -= f;
				cap[i] -= f;
				cap[i ^ 1] += f;
				if (!r) break;
			}
			return c - r;
		};
		Cap res = 0;
		while (bfs()) {
			cur = head;
			res += dfs(s, InfCap);
		}
		return res;
	}

	vector<int> MinCut() {
		vector<int> res;
		assert(sz(dis) == n);
		folr(u, 0, n - 1) if (dis[u] == -1) res.push_back(u);
		return res;
	}
};
