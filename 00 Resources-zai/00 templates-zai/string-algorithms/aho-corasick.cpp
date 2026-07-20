template<char st, int C>
struct AhoCorasick {
	vector<array<int, C>> nxt;
	vector<int> fail;
	vector<ll> cnt;

	int node() {
		nxt.emplace_back().fill(-1);
		fail.push_back(-1);
		cnt.push_back(0);
		return sz(nxt) - 1;
	}

	AhoCorasick() { node(); }

	int insert(const string& s) {
		int u = 0;
		for (auto c : s) {
			c -= st;
			if (nxt[u][c] == -1) nxt[u][c] = node();
			u = nxt[u][c];
		}
		cnt[u] += 1;
		return u;
	}

	void build() {
		vector q{0};
		folr(ind, 0, sz(q) - 1) {
			int u = q[ind];
			folr(c, 0, C - 1) {
				int& v = nxt[u][c];
				int w = fail[u] == -1 ?0 : nxt[fail[u]][c];
				if (v == -1) v = w;
				else {
					fail[v] = w;
					q.push_back(v);
				}
			}
			if (fail[u] != -1) cnt[u] += cnt[fail[u]];
		}
	}

	ll count(const string& s) {
		int u = 0;
		ll res = 0;
		for (auto c : s) {
			c -= st;
			u = nxt[u][c];
			res += cnt[u];
		}
		return res;
	}
};
