#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>k;
	printf("%d\n",1<<32-__builtin_clz(k));
	return 0;
}

