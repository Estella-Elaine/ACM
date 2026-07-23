### DP-USACO 1.1 Broken Necklace(破碎的项链)-环状板子
[P1203 [IOI 1993 / USACO1.1] 坏掉的项链 Broken Necklace - 洛谷](https://www.luogu.com.cn/problem/P1203)
```cpp
#include<bits/stdc++.h>  
using namespace std;  
using ll = long long;  
#define all(a) (a).begin(), (a).end()  
  
void work(){  
    int n;  
    cin >> n;  
    string s;  
    cin >> s;  
    s += s;  
    char c = 'w';  
    int cnt1=0, cnt2=0, cntw=0, ans = 0;  
    for(int i=0; i<n*2; i++){  
        if(s[i] == 'w') ++cnt1, ++cntw;  
        // 如果之前全是白色，或者当前颜色匹配  
        else if(c == 'w' || s[i] == c) ++cnt1, cntw = 0, c = s[i];  
        else{  
            ans = max(ans, cnt1+cnt2);  
            cnt2 = cnt1 - cntw; //因为部分w可以继承，干脆就全部去掉了，继承本轮字母个数  
            cnt1 = cntw + 1; //包含了这一轮的s[i]  
            cntw = 0;  
            c = s[i];  
        }  
    }  
    if(ans == 0) ans = n;  
    ans = min(ans, n);  
    cout << ans << '\n';  
} signed main(){  
    ios::sync_with_stdio(0);  
    cin.tie(0);  
    cout.tie(0);  
        int T=1;  
//    cin >> T;  
    while(T--) work();  
}  
  
/*  
29  
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb  
  
11  
  
8  
rrwwwwbb  
  
8  
*/
```