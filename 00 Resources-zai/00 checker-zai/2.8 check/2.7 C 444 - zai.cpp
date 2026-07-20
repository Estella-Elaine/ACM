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
#define debug(...) sc(96), cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__), sc(39)

void solve(const int& ic) {
	int n;
	cin >> n;
	vector<int> a(n);
	folr(i, 0, n - 1) cin >> a[i];
	sort(all(a));
	auto check = [&](int l, int r, int x = -1) {
		auto submit = [&](int v) {
			if (x == -1) {
				x = v;
				return true;
			}
			return x == v;
		};
		while (l < r) {
			if (!submit(a[l] + a[r])) return false;
			++l;
			--r;
		}
		return l > r; //不能刚好匹配完的话 l==r退出上面的while循环（即中间剩下一个数
	};
	int pos = n - 1;
	while (pos >= 0 and a[pos] == a[n - 1]) --pos;
	set<int> res;
	if (check(0, n - 1)) res.insert(a[0] + a[n - 1]);
	if (check(0, pos, a[n - 1])) res.insert(a[n - 1]);
	for (int x : res) cout << x << ' ';
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int tt = 1;
	// cin >> tt;
	folr(ic, 0, tt - 1) solve(ic);
}
