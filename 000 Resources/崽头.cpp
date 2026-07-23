#include <bits/stdc++.h>

using namespace std;
//using ll = long long;
#define sz(a) (int)(a).size()
//#define all(a) (a).begin(), (a).end()

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

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)  // Debugger

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x = 5;
	long long y = 6;
	vector<int> c = {1, 2};
	set<int> s = {1, 2};
	debug(x, y, c, s); 
}






//¼ì²é´íÎó 
//if(a!=5) throw;

