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
	int n;
	cin >> n;

	vector<ll> r(n + 1), m(n + 1);
	ll mod = 1;
	for(int i = 1; i <= n; ++i){
		cin >> m[i] >> r[i];
		mod *= m[i];
	}

	auto exgcd = [&](auto&& self, ll a, ll b, ll& x, ll& y) -> ll {
		if(!b){
			x = 1, y = 0;
			return a;
		}
		ll d = self(self, b, a % b, y, x);
		y -= a / b * x;
		return d;
	};

	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		ll tmp = mod / m[i];
		ll inv, y;
		exgcd(exgcd, tmp, m[i], inv, y);
		ans = (ans + (__int128)tmp * r[i] * inv % mod) % mod;
	}

	cout << (ans % mod + mod) % mod << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	work();
	return 0;
}