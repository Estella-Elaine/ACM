#include<bits/stdc++.h>
using namespace std;
using ll = long long; 

void work(){
	int n;
	cin >> n;
	vector<ll> a(n);
//	vector<ll> b;
	map<ll, ll> cnt;
	ll maxx = -1;
//	int idx = -1;
	for(ll i=0; i<n; i++){
		cin >> a[i];
//		if(cnt[i] == 0) b.push_back(i);
//		if(a[i] > maxx){
//			maxx = a[i];
//			idx = i;
//		}
		maxx = max(a[i], maxx);
		cnt[a[i]] ++;
//		idx[a[i]] = i;
	}
//	sort(b.begin(), b.end());
//	ll siz = b.size();
//	if(n == 1){
//		cout << 1 << '\n';
//		return;
//	}
//	int cnt = 0;
//	for(int i=0; i<n; i++){
//		if(a[i] == maxx) cnt++;
//	}
	
	
//	for(int i=1; i<=maxx; i++){
//		if(cnt[i] % 2 == 1){
//			x = idx[i];
//			break;
//		}
//	}
	string ans;
	for(int i=0; i<n; i++){
//		int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if(a[i] == maxx){
			if(cnt[maxx] % 2 == 1) ans += '1';
			else ans += '0';
		}
		else{
			if(cnt[maxx] % 2 == 0) ans += '1';
			else ans += '0';
		}
	}
//	if(cnt % 2 == 0){
//		for(int i=0; i<n; i++)	cout << 0;
//		cout << '\n';
//		return;
//	}
//	for(int i=0; i<n; i++){
//		if(i == x) cout << 1;
//		else cout << 0;
//	}
	cout << ans << '\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
	cin >> t;
	while(t--) work();	
}

/*
5
5
1 2 2 3 3
4
2 3 3 3
5
2 3 5 4 5
6
1 1 4 5 1 4
1
3
*/
