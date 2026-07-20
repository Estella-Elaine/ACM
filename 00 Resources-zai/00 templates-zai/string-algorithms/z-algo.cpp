vector<int> zalgo(const string& s) {
	int n = sz(s), l = 0;
	vector z(n, 0);
	folr(i, 1, n - 1) {
		z[i] = max(0, min(z[i - l], l + z[l] - i));
		while (i + z[i] < n and s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] > l + z[l]) l = i;
	}
	return z;
} // on small t: f[i] = max(0, min(i - l < n ? z[i - l] : 0, l + z[l] - i))
