#include<bits/stdc++.h>
using namespace std;
const int Max = 6000;
const int Mod = 1e9+7;
int c[Max][Max];

void work(){
	int n, k;
	cin >> n >> k;
	//预处理 [0,Max] 内 杨辉三角组合数
	for(int i = 0; i < Max; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0 || j == i)
				c[i][j] = 1;
			else
				c[i][j] = (c[i-1][j] + c[i-1][j-1]) % Mod;
		}
	}
	
	//查询一次即可
	cout << c[n][k] % Mod;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
//	cin >> t;
	while(t--){
		work();
	}
}

/*
输出组合数 Cnk （n在下 k在上

这个可以化简为n!/（k!*（n-k）!）
公式Cnk=C(n-1)k + C(n-1)(k-1)
预处理组合数学数：



5 3

10
*/
