template<class T> class Fenwick {
private:
	vector<T> c;
public:
	Fenwick(int n): c(n, 0) {}
	void add(int i, T v) { for (; i < sz(c); i |= i + 1) c[i] += v; }

	T get(int i) {
		T v{};
		for (; i; i &= i - 1) v += c[i - 1];
		return v;
	}
	// sum of [l, r)
	T get(int l, int r) { return get(r) - get(l); }

	int LongestPrefix(T v) {
		int i = 0;
		for (int w = 1 << __lg(sz(c)); w; w >>= 1) if (i + w <= sz(c) and c[i + w - 1] <= v) {
			i += w;
			v -= c[i - 1];
		}
		return i;
	}
};