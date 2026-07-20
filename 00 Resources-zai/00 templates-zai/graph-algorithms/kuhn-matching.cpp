template<class T, T inf = numeric_limits<T>::max()>
auto kuhn(const vector<vector<T>>& e) { // minimum weighted perfect matching
	int n = sz(e), m = n ? sz(e[0]) : 0;
	vector<T> lp(n), rp(m);
	vector lm(n, -1), rm(m, -1);
	folr(u, 0, n - 1) lp[u] = *min_element(all(e[u]));
	auto step = [&](int s) {
		vector q{s}, pre(m, -1);
		vector slack(m, inf);
		auto extend = [&](int v) {
			if (slack[v]) return false;
			if (rm[v] == -1) {
				while (v != -1) {
					int u = pre[v];
					rm[v] = u;
					swap(lm[u], v);
				}
				return true;
			} else q.push_back(rm[v]);
			return false;
		};
		folr(i, 0, n - 1) {
			int u = q[i];
			folr(v, 0, m - 1) {
				if (v == lm[u]) continue;
				T off = e[u][v] - lp[u] - rp[v];
				if (off < slack[v]) {
					slack[v] = off;
					pre[v] = u;
					if (extend(v)) return;
				}
			}
			if (i == sz(q) - 1) {
				T d = inf;
				folr(v, 0, m - 1) if (slack[v]) d = min(d, slack[v]);
				bool found = false;
				for (int u : q) lp[u] += d;
				folr(v, 0, m - 1) {
					if (slack[v]) {
						slack[v] -= d;
						if (!found) found |= extend(v);
					} else rp[v] -= d;
				}
				if (found) return;
			}
		}
	};
	folr(u, 0, n - 1) step(u);
	vector<pair<int, int>> res;
	folr(u, 0, n - 1) if (~lm[u]) res.emplace_back(u, lm[u]);
	return res;
}