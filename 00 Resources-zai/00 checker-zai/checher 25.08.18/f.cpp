#include<bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int n,x,y,z,ans=0,sum = 1,sum1 = 0,max = 1,max2 = 1,sum2 = 0;
	cin>>n>>x>>y>>z;
	vector<int> a(n);
	map<int,int> mp;
	
	for (int i = 0; i < n; i ++){
		cin >> a[i];
	}
	sort(a.begin(),a.end(),less<int>());
	
	for (int i = 1; i < n; i ++){
		if (a[i-1] == a[i]){
			sum ++;			//sum用于统计每个数字出现的次数 
			sum1 ++;			//sum1用于统计整个序列中重复出现的数字的个数 
			if (sum > max){
				max2 = max;
				max = sum;
			}
		}
		else{
			mp[sum] ++;		//mp[i]=x 出现i次的数字有x个 
			sum = 1;
		}
	}
	
	//计算后缀和 mp[1]代表第一个子串中数字的个数 （注：第一个子串中 数字个数最多) 
	for (int i = max-1; i >= 1; i --){
		mp[i] += mp[i+1];
	}
	
	if (x+z <= 2*y){	//此时 重复的数字不应该成为新的上升子串 而是应该合并到之前的子串中  
		ans = (n - sum1) * x + sum1 * y;
		cout << ans << endl;
		return;
	}
	else{
		ans += mp[1] * x;
		for (int i = 2; i <= max; i ++){
			if (mp[i] >= 2){
				ans += (mp[i]-1) * x;
				sum2 ++;			//sum2：上升子列的数量（除了第一个） 
			}
			else if (mp[i] == 1){ 
				ans += (max - max2)*y;	//落单无法成为子串的 合并到之前的子串中 
			}
		}
		ans += sum2 * z;
		cout << ans << endl;
	}
//	for (int i = 0; i <= max; i ++){
//		cout << mp[i] << " ";
//	}
//	cout << endl;
}

signed main(){
	ios::sync_with_stdio(0);                                   
	cin.tie(0),cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		work();
	}
} 


//10
//18
//14 15 8
//2 3 4 5 6 7 7 7 8 9 10 2 3 2 2 5 6 5
