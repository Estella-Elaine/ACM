#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define folr(i, a, n) for (auto i = (a); i <= (n); ++i)
#define forl(i, n, a) for (auto i = (n); i >= (a); --i)
using namespace std;
using ll = long long;

template<class A, class B> string to_string(const pair<A, B>&);
string to_string(const string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; } 

template<class A> string to_string(const A& v) {
	string s = "{";
	for (const auto& x : v) s += (sz(s) > 1 ? ", " : "") + to_string(x);
	return s += "}";    
}

template<class A, class B> string to_string(const pair<A, B>& p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
void debug_out() { cerr << '\n'; }

template<class T, class... U>
void debug_out(const T& x, const U&... args) {
	cerr << ' ' << to_string(x);
	debug_out(args...);
}
// 91: red 93: yellow 96: blue
#define sc(x) cerr << "\033[" << x << "m" 
#define debug(...) //sc(96), cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__), sc(39)

const int M = 28, null = 26, mul = 27;
struct C { int x = null; };

C operator+(const C& u, const C& v) {
	if (u.x == null or v.x == null) return {u.x == null ? v.x : u.x};
	if (u.x == v.x and u.x != mul) return {u.x};
	return {mul};
}

void operator+=(C& u, const C& v) { u = u + v; }
void chmax(int& x, const int& y) { if (x < y) x = y; }

const int mod3 = 998244353, mod7 = 1000'000'007, B = 3917;

void solve(const int& ic) {
	int n, m;
	cin >> n >> m;
	vector<int> U(m), V(m);
	vector<C> W(m);
	vector<vector<int>> r(n);
	folr(i, 0, m - 1) {
		string s;
		cin >> U[i] >> V[i] >> s, --U[i], --V[i];
		W[i].x = s[0] - 'a';
		r[U[i]].emplace_back(V[i]);
		debug(U[i], V[i]);
	}
	vector<int> dfn(n, -1), low(n, -1), sta(n, -1), ins(n, false);
	vector<int> sid(n, -1);
	int top = 0, cid = 0, scc = 0;
	auto dfs = [&](auto&& self, int u)->void {
		low[u] = dfn[u] = cid++;
		sta[top++] = u;
		ins[u] = true;
		for (auto v : r[u]) {	
			if (dfn[v] == -1) {
				self(self, v);
				low[u] = min(low[u], low[v]);
			} else if (ins[v]) low[u] = min(low[u], dfn[v]);
		} 
		if (dfn[u] == low[u]) {
			// debug(u);
			while (top) {
				int v = sta[--top];
				sid[v] = scc;
				ins[v] = false;
				if (v == u) break;
			}
			++scc;
		}
	};
	folr(u, 0, n - 1) if (dfn[u] == -1) dfs(dfs, u);
	// debug(sid, dfn, low);
	vector<C> rc(scc);
	vector<vector<pair<int, C>>> g(scc);
	vector<int> deg(scc, 0);
	folr(i, 0, m - 1) {
		if (sid[U[i]] == sid[V[i]]) rc[sid[U[i]]] += W[i];
		else {
			++deg[sid[V[i]]];
			g[sid[U[i]]].emplace_back(sid[V[i]], W[i]);
		}
	}
	folr(u, 0, scc - 1) if (rc[u].x == mul) {
		cout << "-1\n";
		return;
	}
	const int inf = 1 << 30;
	vector f(scc, vector(2, vector(M, -inf)));
	vector<int> q;
	folr(u, 0, scc - 1) if (!deg[u]) {
		q.push_back(u);
		f[u][rc[u].x != null][rc[u].x] = 0;
	}
	int L = 0;
	folr(ind, 0, sz(q) - 1) {
		int u = q[ind];
		for (auto [v, w] : g[u]) {
			folr(t, 0, 1) folr(c, 0, M - 1) if (f[u][t][c] != -inf) {
				C nc = C{c} + w + rc[v];
				int nt = t or (rc[v].x != null);
				chmax(f[v][nt][nc.x], f[u][t][c] + 1);
				if (nt and nc.x == mul) {
					cout << "-1\n";
					return;
				}
				if (nc.x == mul) L = max(L, f[v][0][nc.x]);
			}
			if (!--deg[v]) q.push_back(v);
		}
	}
	assert(L != 1);
	if (L == 0) {
		cout << 0 << '\n';
		return;
	}
	debug(L, q);
	vector reach(scc, vector(M, false));
	vector<int> dis(scc, -1);
	forl(ind, sz(q) - 1, 0) {
		int u = q[ind];
		if (f[u][0][mul] == L) {
			dis[u] = L;
			reach[u][mul] = true;
		}
		for (auto [v, w] : g[u]) if (dis[v] != -1) folr(c, 0, M - 1) if (f[u][0][c] != -inf) {
			C nc = C{c} + w + rc[v];
			if (rc[v].x != null or !reach[v][nc.x] or f[v][0][nc.x] != f[u][0][c] + 1) continue;
			reach[u][c] = true;
			dis[u] = dis[v] - 1;
			assert(f[u][0][c] == dis[u]);
		}
	}
	vector<int> hf3(scc, -1), hf7(scc, -1), pf(scc, 0);
	debug(dis);
	folr(ind, 0, sz(q) - 1) {
		int u = q[ind];
		if (dis[u] == -1) continue;
		if (dis[u] == 0) {
			hf3[u] = hf7[u] = 0;
			pf[u] = 1;
			debug(__LINE__);
		}
		if (2 * (dis[u] + 1) > L or !pf[u]) continue;
		debug(u, dis[u]);
		for (auto [v, w] : g[u]) if (dis[v] == dis[u] + 1) {
			if (pf[u] == 2) {
				pf[v] = 2;
				continue;
			}
			int h3 = (hf3[u] * ll(B) + w.x) % mod3;
			int h7 = (hf7[u] * ll(B) + w.x) % mod7;
			if (pf[v] == 0) {
				assert(hf3[v] == -1 and hf7[v] == -1);
				hf3[v] = h3;
				hf7[v] = h7;
				pf[v] = 1;
				continue;
			}
			if (h3 != hf3[v] or h7 != hf7[v]) pf[v] = 2;
		}
	}
	vector<int> hb3(scc, -1), hb7(scc, -1), pb(scc, 0);
	forl(ind, sz(q) - 1, 0) {
		int u = q[ind];
		if (dis[u] == -1) continue;
		if (dis[u] == L) {
			hb3[u] = hb7[u] = 0;
			pb[u] = 1;
		}
		if (2 * dis[u] < L) continue;
		debug(u, dis[u], 1);
		for (auto [v, w] : g[u]) if (pb[v] and dis[v] == dis[u] + 1) {
			if (pb[v] == 2) {
				pb[u] = 2;
				break;
			}
			int h3 = (hb3[v] * ll(B) + w.x) % mod3;
			int h7 = (hb7[v] * ll(B) + w.x) % mod7;
			if (pb[u] == 0) {
				assert(hb3[u] == -1 and hb7[u] == -1);
				hb3[u] = h3;
				hb7[u] = h7;
				pb[u] = 1;
				continue;
			}
			if (h3 != hb3[u] or h7 != hb7[u]) {
				pb[u] = 2;
				break;
			}
		}
	}
	auto check = [&](int u, int v) {
		debug(u, v, pf[u], pb[v], hf3[u], hb3[v]);
		if (!pf[u] or !pb[v]) return false;
		if (pf[u] == 2 or pb[v] == 2) return true;
		return hf3[u] != hb3[v] or hf7[u] != hb7[v];
	};
	if (L % 2 == 0) {
		folr(u, 0, scc - 1) if (dis[u] == L / 2 and check(u, u)) {
			cout << L << '\n';
			return;
		}
	} else {
		folr(u, 0, scc - 1) if (dis[u] == L / 2) for (auto [v, w] : g[u]) if (dis[v] == L / 2 + 1 and check(u, v)) {
			cout << L << '\n';
			return;
		}
	}
	cout << L - 1 << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	folr(ic, 0, tt - 1) solve(ic);
}