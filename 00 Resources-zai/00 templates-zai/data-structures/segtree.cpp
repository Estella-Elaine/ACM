template<class U, class T> struct SegTree {
	int n, rt, p = 0;
	vector<int> ls, rs;
	vector<U> sum;
	vector<T> tag;
 
	void update(int u) { sum[u] = sum[ls[u]] + sum[rs[u]]; }
 
	void apply(int u, const T& x) {
		sum[u] += x;
		tag[u] += x;
	}
 
	void push(int u) {
		apply(ls[u], tag[u]);
		apply(rs[u], tag[u]);
		tag[u] = T{};
	}
 
	int build(int l, int r, const vector<U>& a) {
		int u = p++;
		if (r - l == 1) {
			sum[u] = a[l];
			return u;
		}
		int mid = (l + r) / 2;
		ls[u] = build(l, mid, a);
		rs[u] = build(mid, r, a);
		update(u);
		return u;
	}
 
	SegTree(int n) : n(n), ls(n * 2), rs(n * 2), sum(n * 2), tag(n * 2) { rt = build(0, n, vector<U>(n)); }
	SegTree(const vector<U>& a): n(sz(a)), ls(n * 2), rs(n * 2), sum(n * 2), tag(n * 2) { rt = build(0, n, a); }
 
	void set(int i, const U& v, int u, int l, int r) {
		if (r - l == 1) {
			sum[u] = v;
			return;
		}
		int mid = (l + r) / 2;
		push(u);
		i < mid ? set(i, v, ls[u], l, mid) : set(i, v, rs[u], mid, r);
		update(u);
	}
 
	void set(int i, const U& v) { set(i, v, rt, 0, n); }
 
	void add(int x, int y, const T& v, int u, int l, int r) {
		if (r <= x or y <= l) return;
		if (x <= l and r <= y) return apply(u, v);
		int mid = (l + r) / 2;
		push(u);
		add(x, y, v, ls[u], l, mid);
		add(x, y, v, rs[u], mid, r);
		update(u);
	}
 
	void add(int x, int y, const T& v) { add(x, y, v, rt, 0, n); }

	U acc(int x, int y, int u, int l, int r) {
		if (r <= x or y <= l) return U{};
		if (x <= l and r <= y) return sum[u];
		int mid = (l + r) / 2;
		push(u);
		return acc(x, y, ls[u], l, mid) + acc(x, y, rs[u], mid, r);
	}
 
	U acc(int x, int y) { return acc(x, y, rt, 0, n); }
	U at(int i) { return acc(i, i + 1); }
	U total() { return sum[rt]; }
};

struct Node {

	friend Node operator+(const Node& u, const Node& v) {

	}
};

struct Tag {

	friend void operator+=(Node& u, const Tag& v) {

	}

	friend void operator+=(Tag& u, const Tag& v) {

	}
};