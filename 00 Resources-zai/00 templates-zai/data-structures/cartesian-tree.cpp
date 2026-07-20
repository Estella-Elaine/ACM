template<class T> auto CartesianTree(const vector<T>& a, int gr = false) {
	int n = sz(a);
	vector ls(n, -1), rs(n, -1);
	vector<int> sta;
	folr(i, 0, n - 1) {
		while (sz(sta) and ((a[i] < a[sta.back()]) ^ gr)) {
			ls[i] = sta.back();
			sta.pop_back();
		}
		if (sz(sta)) rs[sta.back()] = i;
		sta.push_back(i);
	}
	return make_tuple(sta[0], ls, rs);
} 
