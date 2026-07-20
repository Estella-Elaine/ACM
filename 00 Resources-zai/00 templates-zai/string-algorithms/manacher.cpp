vector<int> manacher(const string& t) {
	string s = "";
	folr(i, 0, 2 * sz(t) - 2) s.push_back((i & 1) ? '#' : t[i >> 1]);
	int n = sz(s), l = 0;
	vector z(n, 1);
	folr(i, 1, n - 1) {
		if (l + z[l] > i) z[i] = min(z[2 * l - i], l + z[l] - i);
		while (i - z[i] >= 0 and i + z[i] < n and s[i - z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] > l + z[l]) l = i;
	}
	folr(i, 0, n - 1) if ((i & 1) == (z[i] & 1)) z[i] -= 1;
	return z;
}
