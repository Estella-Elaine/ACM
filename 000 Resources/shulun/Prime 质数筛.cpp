#include<bits/stdc++.h>
using namespace std;
const int M = 1e6;
vector<int> prim, p(M);

//用小的数取筛选大的数字，确保每个数字只会被自己的最小质因数去筛选
//（数据范围：1~5e6）

void work(){
	int n;
	cin >> n;
	
	//预处理，使得p[i]存储i的最小质因数
	for(int i = 2; i < M; i++){
		if(p[i] == 0){
			p[i] = i;	//p[i]存储i的最小质因数
			prim.push_back(i);
		}
		for(auto j : prim){
			if(i * j >= M) break; //超出数据范围了，没必要
			p[i * j] = j;
			if(i % j == 0) break; //保证“最小”质因数
			//eg. i=4时 p[4*2]=2 break;		(p[4*3]=3 错误)
			//    i=6时 p[6*2]=2 break;		等等...
		}
	}
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x >= 2 && x < M && p[x] == x){
			cout << x << " ";
		}
	}
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
依次输出数组中的质数
5
3 4 5 6 7

3 5 7
*/
