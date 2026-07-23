### 01_Data_Structure_BIT_树状数组_板子
[P3374 【模板】树状数组 1 - 洛谷](https://www.luogu.com.cn/problem/P3374)
```cpp
#include<bits/stdc++.h>  
using namespace std;  
#define int long long  
using ll = long long; 
const int N = 1e6;  

struct BIT{ // 1-base ?
    ll n, ssum[N];

    void init(int _n){
        n = _n;
        for(int i=1; i<=n; i++) ssum[i]=0;
    }

    void add(int x, int v){  // 单点加
        for(int i=x; i<=n; i+=i&-i) ssum[i]+=v;  
    }  
    
    void add(int l, int r, ll v){ // 区间加
        add(l, v);
        add(r+1, -v);
    }

    ll query(int x){  
        ll ans = 0;  
        for(; x>=1; x-=x&-x) ans += ssum[i];  
        return ans;  
    }
};

ll n, m;  
BIT bit;
  
void work(){  
    cin >> n >> m;  
    vector<int> a(n+1);     

    bit.init(n);
    
    for(int i=1; i<=n; i++){  
        cin >> a[i];  
        bit.add(i, a[i]);  
    }  
    for(int i=0; i<m; i++){  
        int op;  
        cin >> op;  
        if(op == 1){  
            int x, k;  
            cin >> x >> k;  
            bit.add(x, k);  
        }  
        else if(op == 2){  
            int x, y;  
            cin >> x >> y;  
            cout<< bit.query(y) - bit.query(x-1) << '\n';  
        }  
    }  
//    for(int i=1;i<=n;i++){  
//        cout<<bit.ssum[i]<<" ";  
//    }  
}  
  
signed main(){  
    ios::sync_with_stdio(0);  
    cin.tie(0);  
    int T=1;  
//    cin >> T;  
    while(T--) work();  
}
  
/*  
2  
5 1001 20 1001  128  
86  
*/
```

zai-板子
```cpp
struct Fenwick {
    vector<int> c;
    Fenwick(int n): c(n) {}
    void add(int i, int x) { for (; i < sz(c); i |= i + 1) (c[i] += x) %= mod; }
  
    int sum(int i) {
        int x = 0;
        for (; i; i &= i - 1) (x += c[i - 1]) %= mod;
        return x;
    }
};
```

##### 离散化
```cpp
void work(){
	int n;
	cin >> n;
	vector<int> a(n+1); 
	for(int i=1; i<=n; i++) cin >> a[i];
	
	auto tmp = a;
	sort(tmp.begin()+1, tmp.end()); // 排序
    tmp.erase(unique(tmp.begin()+1, tmp.end()), tmp.end()); // 去重
    
    for(int i=1; i<=n; i++){ // 查询：查找“第一个不小于 value 的位置”
        a[i] = lower_bound(tmp.begin()+1, tmp.end(), a[i]) - tmp.begin();
    }
    for(int i=1; i<=n; i++) cout << a[i] << " \n"[i == n];
}
/*
6
100 200 300 200 100 200

1 2 3 2 1 2
*/
```