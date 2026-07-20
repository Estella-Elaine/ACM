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
	int n, a = 5;
	cin >> n;
	string s = "test";
	vector<int> v = {1, 2, 3};

	debug(a, s, v);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int tt = 1;
	// cin >> tt;
	folr(ic, 0, tt - 1) solve(ic);
}