#include<bits/stdc++.h>
using namespace std;
using ll = long long; 

int bitlen(int x){
	if(x == 0) return 1;
	return 32-__builtin_clz(x);
}

void work(){
	int a, b;
	cin >> a >> b;
	if(a == b){
		cout << 0 << '\n';
		return;
	}
	int lena = bitlen(a);
	int lenb = bitlen(b);
	if(lena < lenb){
		cout << -1 << '\n';
		return;
	}
	int x = a^b;
	int lenx = bitlen(x);
//	cout << "a^b : " << x << '\n';
	if(x <= a){
		cout << 1 << '\n' << x << '\n';
	}
	else{
		int y = 1LL << (lenx-1);
		x = x - y;
		cout << 2 << '\n';
		cout << x << " " << y << '\n';
	}
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
	cin >> t;
	while(t--) work();	
}

/*
Beautiful XOR
思路：
若a^x=b，则a^b=x
又因为 0<=x<=a，结合异或的不进位性质，
把 >a 的 x 拆成两个数（eg.15 = 7+8


特别注明：__builtin_clz(x) 好用好用！！
int bitlen(int x){
if(x == 0) return 1;
return 32-__builtin_clz(x);
}

*/
