#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

template<typename A>
string to_string(A v) {
	string s = "{";
	for (auto x : v) {
		if (sz(s) > 1) s += ", ";
		s += to_string(x);
	}
	return s += "}";
}

void debug_out() { cerr << "\n"; }

template<typename T, typename... U>
void debug_out(const T& x, const U&... args) {
	cerr << " " << to_string(x);
	debug_out(args...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__) 

int main() {
	mt19937 gen(__builtin_ia32_rdtsc());
	int n = 10;
	cout << n << '\n';
	for (int i = 0; i < 2 * n; ++i) {
		cout << gen() % 30 + 1 << " \n"[i % n == n - 1];
	}
}
