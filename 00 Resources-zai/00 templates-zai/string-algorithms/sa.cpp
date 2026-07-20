struct SA {
	int n;
	vector<int> str, sa, rank, h;

	SA(const string& s): n(sz(s)), str(n + 1), sa(n + 1), rank(n + 1), h(n, 0) {
		auto w = s;
		sort(all(w));
		w.resize(unique(all(w)) - w.begin());
		folr(i, 0, n - 1) str[i] = rank[i] = lower_bound(all(w), s[i]) - w.begin() + 1;
		iota(all(sa), 0);
		++n;
		for (int len = 0; len < n; len = len ? len * 2 : 1) {
			vector cnt(n + 1, 0);
			for (auto v : rank) cnt[v + 1] += 1;
			folr(i, 1, n - 1) cnt[i] += cnt[i - 1];
			vector<int> nsa(n), nrank(n);
			for (auto pos : sa) {
				pos -= len;
				if (pos < 0) pos += n;
				nsa[cnt[rank[pos]]++] = pos;
			}
			swap(sa, nsa);
			int r = 0, lp = -1;
			for (auto p : sa) {
				auto next = [&](int a, int b) { return a + b < n ? a + b : a + b - n; };
				if (~lp) r += rank[p] != rank[lp] or rank[next(p, len)] != rank[next(lp, len)];
				nrank[p] = r;
				lp = p;
			}
			swap(rank, nrank);
		}
		// debug(sa);
		sa = vector(1 + all(sa));
		rank.resize(--n);
		folr(i, 0, n - 1) rank[sa[i]] = i;
		int len = 0;
		folr(i, 0, n - 1) {
			if (len) --len;
			int rk = rank[i];
			if (rk == n - 1) continue;
			while (str[i + len] == str[sa[rk + 1] + len]) ++len;
			h[rk + 1] = len;
		}
	}
};