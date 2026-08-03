#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
适用背景：
树状数组维护的不是原数组，而是“值域频率”。

例如值域是 1 ~ n，支持：
插入一个数 x
删除一个数 x
查询 <= x 的数有多少个
查询当前第 k 小

常见应用：
动态第 k 小
逆序对
排名查询
离散化后维护频率
多重集合替代品
*/

struct BIT{
	int n;
	vector<int> tr;

	BIT(int _n): n(_n), tr(_n + 2) {}

	void add(int x, int v){ // 单点加
		for(; x <= n; x += x & -x){
			tr[x] += v;
		}
	}

	int query(int x){ // 单点查询: 查前缀和 a[1, x]
		int ans = 0;
		for(; x >= 1; x -= x & -x){
			ans += tr[x];
		}
		return ans;
	}

	int kth(int k){
		int x = 0;
		for(int i = 1 << __lg(n); i; i >>= 1){
			if(x + i <= n && tr[x + i] < k){
				x += i;
				k -= tr[x];
			}
		}
		return x + 1;
	}
};

void work(){
	int n, q;
	cin >> n >> q;

	BIT bit(n);

	while(q--){
		int op, x;
		cin >> op >> x;

		if(op == 1){
			bit.add(x, 1);       // 插入 x
		}else if(op == 2){
			bit.add(x, -1);      // 删除 x
		}else if(op == 3){
			cout << bit.query(x) << '\n'; // <= x 的数量
		}else{
			cout << bit.kth(x) << '\n';   // 第 x 小
		}
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