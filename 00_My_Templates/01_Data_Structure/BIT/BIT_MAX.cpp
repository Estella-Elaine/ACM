#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
const ll INF = (1ll << 60);
/*
适用背景：
普通 BIT 维护的是 "和"，但如果操作是单调更新，也可以维护最大值。

常见应用：
LIS 优化
DP 转移最大值
权值压缩后求前缀最优
偏序 DP

注意：这种 BIT 一般不支持普通删除，也不支持随便改小。
*/

struct BIT_Max{
	int n;
	vector<ll> tr;

	BIT_Max(int _n = 0): n(_n), tr(_n + 2, -INF) {}

	void update(int x, ll v){
		for(; x <= n; x += x & -x) tr[x] = max(tr[x], v);
	}

	ll query(int x){
		ll ans = -INF;
		for(; x >= 1; x -= x & -x) ans = max(ans, tr[x]);
		return ans;
	}
};

void work(){
	int n;
	cin >> n;

	vector<int> a(n + 1), b;
	vector<ll> w(n + 1);

	for(int i = 1; i <= n; ++i){
		cin >> a[i] >> w[i];
		b.push_back(a[i]);
	}

	sort(all(b));
	b.erase(unique(all(b)), b.end());

	BIT_Max bit(sz(b));

	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		int x = lower_bound(all(b), a[i]) - b.begin() + 1;
		ll cur = max(0ll, bit.query(x - 1)) + w[i];
		bit.update(x, cur);
		ans = max(ans, cur);
	}

	cout << ans << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while(T--) work();
	return 0;
}