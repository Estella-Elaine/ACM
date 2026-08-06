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

const int N = 1000000;
vector<int> p, mu(N + 1);
vector<bool> np(N + 1);
map<int, int> mp;

void init(){
	np[0] = np[1] = true;
	mu[1] = 1;
	for(int i = 2; i <= N; ++i){
		if(!np[i]){
			p.push_back(i);
			mu[i] = -1;
		}
		for(int x : p){
			if(1ll * i * x > N) break;
			np[i * x] = true;
			if(i % x == 0){
				mu[i * x] = 0;
				break;
			}
			mu[i * x] = -mu[i];
		}
	}
	for(int i = 1; i <= N; ++i){
		mu[i] += mu[i - 1];
	}
}

int msum(int x){
	if(x <= N) return mu[x];
	if(mp.count(x)) return mp[x];

	ll res = 1;
	for(int l = 2, r; l <= x; l = r + 1){
		int v = x / l;
		r = x / v;
		res -= 1ll * (r - l + 1) * msum(v);
	}
	return mp[x] = res;
}

ll calc(int x){
	ll res = 0;
	for(int l = 1, r; l <= x; l = r + 1){
		int v = x / l;
		r = x / v;
		res += 1ll * (msum(r) - msum(l - 1)) * v * v;
	}
	return (res + 1) / 2;
}

void work(){
	int n;
	cin >> n;
	cout << calc(n) << ' ' << msum(n) << '\n';
} 

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T = 1;
	cin >> T;
	while(T--) work();
	return 0;
}