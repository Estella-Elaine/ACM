#include<bits/stdc++.h>
#define int long long
using namespace std;

void work(){
    int n,x,y,z,ans=0;
    cin>>n>>x>>y>>z;
    vector<int> num(n+1),times(n+1);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num[a]++;
    }
    int maxnum=0;
    for(int i=1;i<=n;i++) times[num[i]]++,maxnum=max(maxnum,num[i]);
    for(int i=maxnum-1;i>=1;i--) times[i]=times[i+1]+times[i];
    // for(int i=1;i<=maxnum;i++) cout<<times[i]<<" ";
    // cout<<endl;
    ans+=times[1]*x;
    for(int i=2;i<=maxnum;i++){
        ans+=max(z+(times[i]-1)*x,times[i]*y);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        work();
    }
    system("pause");
}
