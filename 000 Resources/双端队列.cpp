#include<bits/stdc++.h>
using namespace std;

int main(){
	int S;
	cin>>S; 
	deque<int> dq; 
	string ad,lr;
	int k,number=0;
	for(int i=0;i<S;i++){
		cin>>ad;
		if(ad=="A"){
			number++;
			cin>>lr;
			if(lr=="L"){
				dq.push_front(number);
			}
			else{
				dq.push_back(number);
			}
		}
		else{
			cin>>lr>>k;
			if(lr=="L"){
				dq.erase(dq.begin(),dq.begin()+min(k,(int)dq.size()));	
				//min() : 防止越界；进行比较的两者数据类型要一致 
			}
			else{
				dq.erase(dq.end()-min(k,(int)dq.size()),dq.end());
			}
		}
		
	} 
	for(int num:dq){
		cout<<num<<endl;
	}
}

//signed main(){
//	int t=1;
//	cin>>t;
//	while(t--){
//		work();
//	}
//}

