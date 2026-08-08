#include<bits/stdc++.h>
using namespace std;
using i64 = long long; 
using ull = unsigned long long; 
#define sz(a) int((a).size())
#define pii pair<int, int>
#define pll pair<i64, i64>
#define all(a) (a).begin(), (a).end()
const int inf = (1 << 30);
const i64 INF = (1ll << 60);
const double PI = acos(-1);

const int N = 300000 + 5;

int pri[N], mu[N], a[N], tmp[N], cnt[N], ans[N], tot;
bool np[N];
vector<int> fac[N];

void work(){
	static bool ok = false;

	if(!ok){
		auto init = [&]() -> void {
			mu[1] = 1;
			for(int i = 2; i < N; ++i){
				if(!np[i]){
					pri[++tot] = i;
					mu[i] = -1;
				}
				for(int j = 1; j <= tot && 1ll * i * pri[j] < N; ++j){
					int x = i * pri[j];
					np[x] = true;
					if(i % pri[j] == 0){
						mu[x] = 0;
						break;
					}
					mu[x] = -mu[i];
				}
			}

			for(int i = 1; i < N; ++i){
				if(!mu[i]) continue;
				for(int j = i; j < N; j += i){
					fac[j].push_back(i);
				}
			}
		};

		init();
		ok = true;
	}

	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		tmp[i] = a[i];
	}

	sort(tmp + 1, tmp + n + 1);

	vector<int> q(n);
	iota(all(q), 1);

	auto solve = [&](auto&& self, int l, int r, vector<int>& q) -> void {
		if(q.empty() || l > r) return;

		if(l == r){
			for(auto i : q) ans[tmp[i]] = tmp[l];
			return;
		}

		int mid = (l + r) >> 1;
		for(int i = mid + 1; i <= r; ++i){
			for(auto x : fac[tmp[i]]) ++cnt[x];
		}

		vector<int> ql, qr;
		for(auto i : q){
			int sum = 0;
			for(auto x : fac[tmp[i]]){
				sum += mu[x] * cnt[x];
			}

			if(i > mid && tmp[i] == 1) --sum;

			if(sum > 0) qr.push_back(i);
			else ql.push_back(i);
		}

		for(int i = mid + 1; i <= r; ++i){
			for(auto x : fac[tmp[i]]) --cnt[x];
		}

		self(self, mid + 1, r, qr);
		self(self, l, mid, ql);
	};

	solve(solve, 1, n, q);

	for(int i = 1; i <= n; ++i){
		cout << ans[a[i]] << " \n"[i == n];
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while(T--) work();
	return 0;
}