#include<bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long; 

void work(){
	int n;
	cin >> n;
	vector<int> a(n+1); 
	for(int i=1; i<=n; i++) cin >> a[i];

	auto tmp = a;
	sort(tmp.begin()+1, tmp.end()); // 排序
	tmp.erase(unique(tmp.begin()+1, tmp.end()), tmp.end()); // 去重
	for(int i=1; i<=n; i++){ // 查询：查找“第一个不小于 value 的位置”
		a[i] = lower_bound(tmp.begin()+1, tmp.end(), a[i]) - tmp.begin();
	}
	for(int i=1; i<=n; i++) cout << a[i] << " \n"[i == n];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
//	cin >> T;
	while(T--){
		work();
	}
}

/*
6
100 200 300 200 100 200

1 2 3 2 1 2
*/