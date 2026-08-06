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

// 最长严格上升子序列 (具体的路径)

void work(){
	int n;
	cin >> n;

	vector<int> a(n + 1), dp, id, pre(n + 1, -1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];

		// auto it = upper_bound(all(dp), a[i]); // 最长不降子序列
		auto it = lower_bound(all(dp), a[i]);
		int p = it - dp.begin();

		if(it == dp.end()){
			dp.push_back(a[i]);
			id.push_back(i);
		}else{
			*it = a[i];
			id[p] = i;
		}

		if(p > 0){
			pre[i] = id[p - 1];
		}
	}

	vector<int> ans;
	for(int x = id.back(); x != -1; x = pre[x]){
		ans.push_back(a[x]);
	}
	reverse(all(ans));

	cout << sz(ans) << '\n';
	for(auto x : ans){
		cout << x << " \n"[x == ans.back()];
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}