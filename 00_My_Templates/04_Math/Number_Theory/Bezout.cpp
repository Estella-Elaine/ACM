#include<bits/stdc++.h>
using namespace std;

void exgcd(int a, int b, int &x, int &y){
	if(b==0){
		x=1, y=0;
		return;
	}
	exgcd(b, a&b, x, y);
	int t = x;
	x = y;
	y = t-a/b*y;	
}

void work(){
	int n;
	cin >> n;
	vector<int> a(n);
	int last = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(a[i] < 0) a[i] *= (-1);
		last = gcd(last, a[i]);
	}
	cout << (last<0 ? -last : last) << '\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--) work();
}