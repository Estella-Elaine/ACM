#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len=s.size();
    if(len==4){
        int x=stoi(s);
        if(x%100<22){
            s="20"+s;
        }
        else{
            s="19"+s;
        }
    }
    s.insert(s.begin()+4,'-');
    //如果要插入字符串而不是单个字符，
	//可以使用：s.insert(4, "---");
}
