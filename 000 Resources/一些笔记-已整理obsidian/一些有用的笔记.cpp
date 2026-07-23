#include<bits/stdc++.h>
#define int longlong
typedef longlong ll;
using namespace std;

//自定义函数模板
void work()
{
	int n;
	cin >>n;
	vector<int> a(n + 1);
	for (int i = 0;i < n; i++)
	{
		...
	}
}

signed main()
{
	int T = 1;
//	cin >> T;
	while (T--)
	{
		work();
	}
	return 0;
}

//快速幂算法模板 
int fastpow(int a,int b)
{
	int ans = 1;
	while(b)
	{
		if (b&1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

int Mul(int a, int b){
	int ans = 0;
	while(b){
		if(b&1) ans += a;
		a+=a;
		b >> 1;
	}
	return ans;
}

const int N = 1e7;
vector<int> prim;
vector<int> p(N);
void primesa(){
	for(int i=2; i<N; ++i){
		if(p[i] == 0){
			p[i] = i;
			prim.push_back(i);
		}
		for(auto j : prim){
			if(i * j >= N) break;
			p[i*j] = j;
			if(i % j == 0) break;
		}
	}
}

//EOF要少用
while(~scanf("%d%d",&a,&b)) 
while(cin >>a >>b)
{
	
} 
cout << fixed<<setprecision()
