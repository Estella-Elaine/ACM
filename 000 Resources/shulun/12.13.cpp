#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	int tmp=n;
	while(tmp>0)
	{
		s=char((tmp%2)+'0')+s;
		tmp/=2;
	}
	cout<<s<<endl;
	int cnt=0;
	
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='0') cnt++;
		else break;
	}
	
	cout<<cnt<<endl;
	return 0;
}

