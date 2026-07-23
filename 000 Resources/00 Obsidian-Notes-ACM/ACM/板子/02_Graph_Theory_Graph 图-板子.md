### 02_Graph_Theory_Graph 图-板子
##### 图的存储：
[B3643 图的存储 - 洛谷](https://www.luogu.com.cn/problem/B3643)
```cpp
#include<bits/stdc++.h>  
//#define int long long  
using namespace std;  
using ll=long long;  
  
void work(){  
    int n,m;  
    cin>>n>>m;         vector<set<int> > g(n+1);  
    vector<vector<int> > adj(n+1,vector<int>(n+1,0));  
        for(int i=1;i<=m;i++){  
        int x,y;  
        cin>>x>>y;  
        g[x].insert(y);  
        g[y].insert(x);  
                adj[x][y]=1;  
        adj[y][x]=1;  
    }  
        for(int i=1;i<=n;i++){  
        for(int j=1;j<=n;j++){  
            cout<<adj[i][j]<<" ";  
        }  
        cout<<'\n';  
    }  
        for(int i=1;i<=n;i++){  
        cout<<g[i].size()<<" ";  
        for(auto y:g[i]){  
            cout<<y<<" ";  
        }  
        cout<<'\n';  
    }  
} signed main(){  
    ios::sync_with_stdio(0);  
    cin.tie(0);  
        int t=1;  
//    cin>>t;  
    while(t--){  
        work();  
    }  
}  
/*  
5 5  
1 2  
2 3  
3 5  
1 3  
3 4  
  
0 1 1 0 0  
1 0 1 0 0  
1 1 0 1 1  
0 0 1 0 0  
0 0 1 0 0  
2 2 3  
2 1 3  
4 1 2 4 5  
1 3  
1 3  
*/
```

##### 图的遍历：
[B3862 图的遍历（简单版） - 洛谷](https://www.luogu.com.cn/problem/B3862)
```cpp
#include<bits/stdc++.h>  
using namespace std;  
using ll=long long;  
  
void work(){  
    int n,m;  
    cin>>n>>m;         vector<set<int> > g(n+1);  
    vector<vector<int> > adj(n+1,vector<int>(n+1,0));  
    for(int i=1;i<=m;i++){  
        int x,y;  
        cin>>x>>y;  
        g[x].insert(y);  
    }  
        int ans=0;  
    vector<int> vis(n+1);  
    auto dfs=[&](auto &&self,int x) -> void{  
        ans=max(ans,x);  
        for(auto y:g[x]){  
            if(vis[y]) continue;  
            vis[y]=1;  
            self(self,y);  
        }  
    };  
    for(int i=1;i<=n;i++){  
        fill(vis.begin(),vis.end(),0);  
        ans=0;  
        dfs(dfs,i);  
        cout<<ans<<' ';  
    }  
    } signed main(){  
    ios::sync_with_stdio(0);  
    cin.tie(0);  
        int t=1;  
//    cin>>t;  
    while(t--){  
        work();  
    }  
}
```