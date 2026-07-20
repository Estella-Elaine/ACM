#include<bits/stdc++.h>
#define int long long
using namespace std;

void work(){
    int n,q;
    cin>>n>>q;
    string S;
    cin>>S;
    for(int i=0;i<q;i++){
        string s;
        int a,ans=0;
        cin>>s>>a;
        int sum=0;
        for(int j=0;j<s.length();j++){
            if(s[j]==S[a-1+j]){
                sum++;
            }else{
                ans+=sum*(sum+1)/2;
                sum=0;
            }
            //cout<<j<<" "<<sum<<endl;
        }
        ans+=sum*(sum+1)/2;
        cout<<ans<<endl;
    }
}
 
signed main(){
     
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
     
    int T=1;
    //cin>>T;
    while(T--){
        work();
    }  
     
}
