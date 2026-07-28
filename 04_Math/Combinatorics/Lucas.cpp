#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
using ull = unsigned long long; 
#define sz(a) int((a).size())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) (a).begin(), (a).end()
const int inf = (1 << 30);
const ll INF = (1ll << 60);
const double PI = acos(-1);

void work(){
	int n, m, p;
	cin >> n >> m >> p;

	vector<int> f(p), inv(p);
	f[0] = 1;
	for(int i = 1; i < p; ++i){
		f[i] = 1ll * f[i - 1] * i % p;
	}

	inv[0] = 1;
	if(p > 1) inv[1] = 1;
	for(int i = 2; i < p; ++i){
		inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	}
	for(int i = 1; i < p; ++i){
		inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	}

	auto comb = [&](int a, int b) -> int {
		if(a < b) return 0;
		return 1ll * f[a] * inv[b] % p * inv[a - b] % p;
	};

	auto lucas = [&](auto&& self, int a, int b) -> int {
		if(!b) return 1;
		return 1ll * comb(a % p, b % p) * self(self, a / p, b / p) % p;
	};

	cout << lucas(lucas, n + m, n) << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}