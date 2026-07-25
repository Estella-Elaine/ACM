#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long; 
using ull = unsigned long long; 
const ll inf = (1ll << 60);
const int M = 1e6+5;
const double PI = acos(-1);

template<class A> string to_string(const A& v) {
	string s = "{";
	for (const auto& x : v) s += ((s).size() > 1 ? ", " : "") + to_string(x);
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
	int n;
	vector<int> a(n), b(n), c(n, 0);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		if(a[i] != b[i]) c[i] = 1;
	}
	ll cur = 0, ans = 0;
	bool ok1 = 1, ok2 = 1; // 当前是坏串，当前坏串里面还没有好数
	int l1 = 0, l2 = 0;
	for(int i = 0; i < n; ++i){
		if(c[i] == 1){
			if(ok1) l1 = i;
			ok1 = 0;
			cur += a[i];
			cout << "1 ";
		}
		else if(!ok1){
			if(ok2) l2 = i;
			ok2 = 0;
			cur += a[i];
			cout << "2 ";
		}

		if(cur % 2 == 1){
			for(int j = l1; j <= i; ++j){
				c[j] = 1 - c[j];
			}
			if(i == n-1) break;
			i = l2 - 1;
			l1 = l2 = i;
			ok1 = 1, ok2 = 1;
			cur = 0;
			++ans;
		}
		cout << i << " " << l1 << " " << l1 << " " << cur << '\n';
		// debug(i);
		// debug(i, l1, l2, cur, ans);
	}

	for(int i = 0; i < n; ++i){
		if(c[i]){
			cout << "-1\n";
			return;
		}
	}
	cout << ans << '\n';

} 

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	
	while(T--){
		work();
	}
	return 0;
}