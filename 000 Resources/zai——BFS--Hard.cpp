#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define folr(i, a, n) for (auto i = (a); i <= (n); ++i)
#define forl(i, n, a) for (auto i = (n); i >= (a); --i)
using namespace std;
using ll = long long;

template<class A> string to_string(const A& v) {
	string s = "{";
	for (const auto &x : v) s += (sz(s) > 1 ? ", " : "") + to_string(x);
	return s += "}";
}

void debug_out() { cerr << '\n'; }
template<class U, class... T> void debug_out(const U& x, const T&... args) {
	cerr << ' ' << to_string(x);
	debug_out(args...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct DSU {
	vector<int> te;
	DSU(int n): te(n) { iota(all(te), 0); }
	int find(int u) { return u == te[u] ? u : te[u] = find(te[u]); }
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	assert(0 <= k and k < m and __gcd(k, m) == 1);
	folr(i, 2, m - 1) assert(m % i != 0); // m is prime!!
	vector inv(m, 1);
	inv[0] = 0;
	folr(i, 2, m - 1) inv[i] = (m - m / i) * ll(inv[m % i]) % m;
	DSU U(n);
	vector id(m, -1), dis(m, -1);
	folr(i, 0, n - 1) {
		int u;
		cin >> u;
		id[u] = i;
	}
	vector<int> q;
	folr(u, 0, m - 1) if (id[u] != -1) {
		dis[u] = 0;
		q.push_back(u);
	}
	ll res = 0;
	folr(ind, 0, sz(q) - 1) {
		int u = q[ind];
		// debug(u, dis[u], id[u]);
		for (int v : {(u + k) % m, (u + m - k) % m, int(u * ll(k) % m), int(u * ll(inv[k]) % m)}) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push_back(v);
				id[v] = id[u];
			} else if (id[v] != id[u] and U.find(id[u]) != U.find(id[v])) {
				// debug(U.find(id[u]), U.find(id[v]));
				res += dis[u] + dis[v] + 1;
				U.te[U.find(id[u])] = U.find(id[v]);
			}
		}
	}
	folr(u, 0, n - 2) assert(U.find(u) == U.find(u + 1));
	res += n - 1;
	cout << res << '\n';
}
/*
Statement:
	given m. n numbers in range [0, m), k in range [0, m). Each operation can
	make a set of same value numbers + - * / k mod m. How many 
	operations does it take to make all the numbers same?

Input Sample:
	3 7 3
	0 2 4
Output Sample:
	5

Explanation:
	4 + 3 = 0
	(2 / 3) - 3 = 0
	merge takes 2
	3 + 2 = 5
*/
