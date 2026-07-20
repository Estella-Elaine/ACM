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
	int cnt = 0;
	while (true) {
		system("data.exe > f.in");
		system("f.exe < f.in > f.out");
		system("brute.exe < f.in > f.ans");
		if (system("fc f.out f.ans")) {
			return cout << "wa " << ++cnt << '\n', 0;
		}
		cout << "ac " << ++cnt << '\n';
	}
}
