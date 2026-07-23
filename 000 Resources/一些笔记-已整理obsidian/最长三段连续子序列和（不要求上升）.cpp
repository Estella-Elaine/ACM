#include<bits/stdc++.h>
using namespace std;

void run(){
	int n;cin>>n;
	vector<int> a(n+1);
	vector<int> ans1(n+1,-1e9);
	vector<int> ans2(n+1,-1e9);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	ans1[1] = a[1];
	ans2[n] = a[n];
	int maxn = a[1];
	
	int tmp = a[1];
	for(int i=2;i<=n;i++){
		int t = max(a[i]+tmp,a[i]);
		maxn = max({tmp,maxn,t});
		ans1[i] = maxn;
	}
	
	tmp = a[n];
	maxn = a[n];
	for(int i=n-1;i>=1;i--){
		int t = max(a[i]+tmp,a[i]);
		maxn = max({tmp,maxn,t});
		ans2[i] = maxn;		
	}
	
	maxn = -1e9;
	for(int i=3;i<=n-2;i++){
		maxn = max((ans1[i-2]+ans2[i+2]+a[i]),maxn);
	}
	cout<<maxn<<"\n";
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;cin>>t;
	while(t--) run();
}
