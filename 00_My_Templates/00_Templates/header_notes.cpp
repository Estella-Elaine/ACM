#include<bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long; 
const double PI = acos(-1);
// #include <cassert>
// #define DEBUG 1 	//提交时注释掉防止TLE

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


void work(){
	
	// 两种很好用的越界查错方法
	// assert(i < 0 && "循环1 数组越界"); 	// eg.循环中数组越界检查下标
	// a.at(idx) = 10;  vector 中直接对可疑的检查是否越界

	// 旧版debug写法
	// #ifdef DEBUG
	// 	cerr << "Current n: " << n << '\n';
	// #endif
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
//	cin >> T;
	while(T--){
		work();
	}
}
/*

*/