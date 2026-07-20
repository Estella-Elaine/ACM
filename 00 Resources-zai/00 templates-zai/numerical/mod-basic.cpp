constexpr int mod = 998244353;

void reduce(int& x) { if (x >= mod) x -= mod; }

int power(int a, int x = mod - 2) {
	int p = 1;
	for (; x; x >>= 1) {
		if (x & 1) p = p * (ll)a % mod;
		a = a * (ll)a % mod;
	}
	return p;
}

vector<int> fac{1, 1}, ifac{1, 1}, inv{0, 1};

void AugFac() {
	int n = sz(fac);
	fac.push_back(fac.back() * (ll)n % mod);
	inv.push_back(inv[mod % n] * (ll)(mod - mod / n) % mod);
	ifac.push_back(ifac.back() * (ll)inv[n] % mod);
}

int comb(int n, int m) {
	if (!(0 <= m and m <= n)) return 0;
	while (sz(fac) <= n) AugFac();
	return fac[n] * (ll)ifac[m] % mod * ifac[n - m] % mod;
}