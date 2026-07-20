template<int N> struct PST {
	int p = 1, ls[N]{}, rs[N]{}, s[N]{};

	int add(int i, int x, int u, int l, int r) {
		int v = p++;
		ls[v] = ls[u];
		rs[v] = rs[u];
		s[v] = s[u] + x;
		if (r - l == 1) return v;
		int mid = (l + r) / 2;
		if (i < mid) ls[v] = add(i, x, ls[u], l, mid);
		else rs[v] = add(i, x, rs[u], mid, r);
		return v;
	}

	int kth(int k, int u, int v, int l, int r) {
		if (r - l == 1) return l;
		int mid = (l + r) / 2;
		int nk = k - (s[ls[v]] - s[ls[u]]);
		if (nk < 0) return kth(k, ls[u], ls[v], l, mid);
		return kth(nk, rs[u], rs[v], mid, r);
	}
};