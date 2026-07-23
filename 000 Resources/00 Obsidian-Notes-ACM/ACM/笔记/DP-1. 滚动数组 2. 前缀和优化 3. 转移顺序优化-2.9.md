```cpp
#include<bits/stdc++.h>  
using namespace std;  
using ll = long long; const ll inf = 1ll <<  60;  
  
void work(){  
    int n;  
    cin >> n;  
    ll sum = 0, dp1 = -inf, dp2 = -inf, dp3 = -inf;  
    for(int i=0; i<n; i++){  
        int x;  
        cin >> x;  
        sum += x;  
        if(i > 1) dp3 = max(dp3, dp2 + x*3);  
        if(i > 0) dp2 = max(dp2, dp1 + x*2);  
        dp1 = max(dp1, sum);
        
// 		  dp1 = max(dp1, sum);  
//        if(i > 0) dp2 = max(dp2, dp1 + x*2);  
//        if(i > 1) dp3 = max(dp3, dp2 + x*3);  
//        cout << "dp1: " << dp1 << " dp2: " << dp2 << " dp3: " << dp3 << '\n';  
    }  
    cout << dp3 << '\n';  
}  
signed main(){  
    ios::sync_with_stdio(0);  
    cin.tie(0);  
	int t=1;  
//    cin >> t;  
    while(t--) work();
}  
  
/*  
8  
3 -1 4 -1 5 -9 2 6  
34  
  
6  
2 -1 -100 50 1 2  
150  
  
3  
1 2 3
14  
*/
```

最重要的就是这三者更新的顺序：
```cpp
if(i > 1) dp3 = max(dp3, dp2 + x*3);  
if(i > 0) dp2 = max(dp2, dp1 + x*2);  
dp1 = max(dp1, sum);
```

如果倒过来，先更新dp1 再dp2，最后dp3的话，那么同一个数会被反复加好多遍，可以尝试一下：
```cpp
dp1 = max(dp1, sum);  
if(i > 0) dp2 = max(dp2, dp1 + x*2);  
if(i > 1) dp3 = max(dp3, dp2 + x*3);  
cout << "dp1: " << dp1 << " dp2: " << dp2 << " dp3: " << dp3 << '\n';
```
Eg. （错误的）![[Pasted image 20260211111231.png]]
同一个数x，会在同一轮中，依次被加入当前这一轮的dp1(+x)，dp2(+2x)，dp3(+3x)，就导致了重复

而正解应该是：![[Pasted image 20260211111541.png]]
同一个数x，会在同一轮中，依次被加入当前这一轮的dp3(+3x)，下一轮的dp1(+x)，下一轮的dp2(+2x)，就实现了循环更新且不会重复

那么区别就显而易见了