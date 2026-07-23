#include<bits/stdc++.h>
using namespace std;
using ll = long long; 

void work(){
	ll n;
	cin >> n;
	ll a = 1LL << 31;
	cout << a*n << " " << (a+1)*n << '\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t=1;
	cin >> t;
	while(t--) work();	
}
/*
定义 (a, b) 为一个组合，组合的值为 (an xor bn)
题目的关键点是 a != b，否则答案就是 0 了。

所以容易想到 a = 1 b = 2，
根据|a - b| <= a xor b <= a + b，
得出value(a, b) <= 3n，
所以答案 <= 3n。

也就是说对于一个组合 (a, b)，如果 b - a >= 3，
那么这个组合就严格不如 (a = 1, b = 2) 优。

所以我们只需要考虑所有 (a, a + 1), (a, a + 2)，
那么 an xor (a + 1)n >= n，再根据 x xor y >= |x - y|，
那么 an xor (a + 1)n 能等于 n 吗？开始构造：a = 2 ^ 31，b = 2 ^ 31 + 1
所以得出答案 >= n 且答案可以等于 n，即gcd(x,y)
*/

