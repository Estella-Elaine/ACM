constexpr int mod = 998244353, G = 3;

void reduce(int& x) { if (x >= mod) x -= mod; }

int power(int a, int x = mod - 2) {
	int p = 1;
	for (; x; x >>= 1) {
		if (x & 1) p = p * (ll)a % mod;
		a = a * (ll)a % mod;
	}
	return p;
}

vector<int> rev, w{0, 1};

void dft(vector<int>& a) {
	int n = sz(a);
	if (n != sz(rev)) {
		rev.resize(n);
		folr(i, 0, n - 1) rev[i] = (rev[i >> 1] >> 1) | (i & 1) * (n >> 1);
	}
	int nw = sz(w);
	if (nw < n) {
		w.resize(n);
		for (; nw < n; nw *= 2) {
			const int wn = power(G, (mod - 1) / (nw << 1));
			folr(i, nw / 2, nw - 1) w[i << 1 | 1] = (w[i << 1] = w[i]) * (ll)wn % mod;
		}
 	}
 	folr(i, 0, n - 1) if (i < rev[i]) swap(a[i], a[rev[i]]);
 	for (int m = 1; m < n; m <<= 1) for (int i = 0; i < n; i += (m << 1)) folr(j, 0, m - 1) {
 		const int u = a[i | j];
 		const int v = w[m | j] * (ll)a[i | m | j] % mod;
 		int x = u + v;
		if (x >= mod) x -= mod;
		a[i | j] = x;
		x = u - v;
		if (x < 0) x += mod;
		a[i | m | j] = x;
 	}
}

void idft(vector<int>& a) {
	int n = sz(a), inv = n == 1 ? 1 : mod - mod / n;
	reverse(1 + all(a));
	dft(a);
	folr(i, 0, n - 1) a[i] = a[i] * (ll)inv % mod;
}

vector<int> operator*(vector<int> a, vector<int> b) {
	int mx = sz(a) + sz(b) - 1;
	int n = 1 << (32 - __builtin_clz(mx - 1));
	a.resize(n, 0);
	dft(a);
	b.resize(n, 0);
	dft(b);
	vector<int> c(n);
	folr(i, 0, n - 1) c[i] = a[i] * (ll)b[i] % mod;
	idft(c);
	c.resize(mx);
	return c;
}