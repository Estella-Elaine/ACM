#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
    int n,q;
    string S;
    cin >> n >> q;
    cin >> S;
    for (int i = 0; i < q; i ++)
    {
    	string T;
    	int a,sum = 0,ans = 0;
    	cin >> T >> a;
    	for (int j = 0; j < T.length(); j ++)
    	{
    		if (T[j] == S[j+a-1])
    		{
    			sum += 1;
			}
			else
			{
				sum = sum * (sum + 1) / 2;
				ans += sum;
				sum = 0;
			}
		}
		sum = sum * (sum + 1) / 2;
		ans += sum;
		cout << ans << endl;
	}
}
