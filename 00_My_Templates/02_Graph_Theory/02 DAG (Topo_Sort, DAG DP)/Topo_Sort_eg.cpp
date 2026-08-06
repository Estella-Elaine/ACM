#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define folr(i, a, n) for (auto i = (a); i <= (n); ++i)
#define forl(i, n, a) for (auto i = (n); i >= (a); --i)
using namespace std;
using ll = long long;

void work() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> a(m);
	vector sgn(n, false); // sign
	for (auto& [o, i, j] : a) { // 很棒的一种写法
		cin >> o >> i >> j, --o, --i, --j;
		if (i == j) sgn[i] = o; 
	}

	// 建有向图 根据节点绝对值的相对大小： 大 -> 小
	vector<vector<int>> g(n);
	vector deg(n, 0); // 记录入度
	for (auto [o, i, j] : a) {
		if (sgn[i] != sgn[j]) { // 异号就要连边, 以找到平衡
			if (o != sgn[i]) swap(i, j); // i 对应 主导
			g[i].push_back(j); // 主导 -> 被动 即 大 -> 小
			++deg[j];
		} else if (sgn[i] != o) { // 同号但是不符就无解
			cout << "NO\n";
			return;
		}
	}

	// 拓扑排序 (大 -> 小), 保证所有 大的 都比 小的 先访问(赋值)到
	vector<int> q;
	folr(u, 0, n - 1) if (!deg[u]) q.push_back(u);
	int cur = n;
	vector val(n, -1);
	folr(i, 0, sz(q) - 1) {
		int u = q[i];
		val[u] = cur--;
		for (int v : g[u]) if (!--deg[v]) q.push_back(v);
	}
	if (sz(q) != n) { // 有环, 无解
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	folr(u, 0, n - 1) {
		if (sgn[u]) val[u] = -val[u];
		cout << val[u] << ' ';
	}
	cout << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while(T--) work();
	return 0;
}