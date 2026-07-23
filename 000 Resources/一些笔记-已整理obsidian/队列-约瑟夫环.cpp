 #include<bits/stdc++.h>
 #define int long long
 using namespace std;

 void work(){
    int n,m;
    cin>>n>>m;
    int x=0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int cnt=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(cnt==m){
            cout<<x<<" ";
            cnt=0;
        }
        else{
            q.push(x);
        }
        cnt++;
    }
 }

 signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        work();
    }
 }
