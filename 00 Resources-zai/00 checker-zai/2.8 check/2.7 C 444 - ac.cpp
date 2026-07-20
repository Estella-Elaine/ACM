#include<bits/stdc++.h>
using namespace std;
using ll = long long; 

void work(){
	int n;
	cin >> n;
	vector<ll> a(n);
	set<ll> ans;
	for(int i=0; i<n; i++) cin >> a[i];
	
	sort(a.begin(), a.end());
	
	int idx = -1;
	for(int i=n-2; i>=0; i--){
		if(a[i] != a[n-1]){
			idx = i;
			break;
		}
	}
	
	//答案是a[n-1]
	int p1=0, q1=idx;
	while(p1 < q1){
		if(a[p1] + a[q1] != a[n-1]) break;
		p1++,q1--;
	}
	if(p1 > q1) ans.insert(a[n-1]);
	
	
	//答案是a[0] + a[n-1]
	ll x = a[0] + a[n-1];
	int p=1, q=n-2;
	while(p < q){
		if(a[p] + a[q] != x) break;
		p++,q--;
	}
	if(p > q) ans.insert(x);
	
	//输出
	for(auto anss : ans){
		cout << anss << " ";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
//	cin >> t;
	
	while(t--) work();	
}

/*
8
9 9 8 8 1 2 1 2

6
9 9 8 1 1 8
*/
