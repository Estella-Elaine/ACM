#include<bits/stdc++.h>
using namespace std;

void f(int &x){
	
}

int main()
{
	int a[10];
	cout<<a[2]<<endl;
	int n=10;
	f(n);
	for(int i=0;i<n;i++){
		static int ans=0;
		ans++;
		cout<<ans<<'\n';
	}
	return 0;
}

