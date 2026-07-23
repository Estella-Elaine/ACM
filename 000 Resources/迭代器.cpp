#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int m;
	cin>>m; 
    set<int> house;
    
    while(m--){
	    int op,length;
	    cin>>op>>length;
	    
	    if(op == 1) {
	        if(house.find(length) != house.end()){
	            cout<<"Already Exist"<<endl;
	        }
			else{
	            house.insert(length);
	        }
	    }
		else{
	        if(house.empty()){
	            cout<<"Empty"<<endl;
	            continue;
	        }
	        
	        auto it=house.lower_bound(length); //迭代器 
	        int ans;
	        
	        if (it==house.end()) {
	            ans=*prev(it);
	        } 
			else if (it == house.begin()) {
	            ans = *it;
	        } 
	        
	        //学习迭代器写法：
			//prev(it) 返回迭代器 it 的前一个位置的迭代器
			//* 解引用，获取该迭代器指向的值
			//所以 *prev(it) 就是 it 前一个元素的值
			
	//		cout << *prev(it); // 输出 3（5 的前一个元素）
	//		cout << *it;       // 输出 5
	//		cout << *next(it); // 输出 7（5 的后一个元素）
	
			else {
	            int succ = *it;
	            int pred = *prev(it);
	            if (succ-length<length-pred){
	                ans=succ;
	            } 
				else {
	                ans=pred;
	            }
	        }
	        
	        cout<<ans<<endl;
	        house.erase(ans);
	    }
	}
}

//signed main()
//{
//	int t=1;
//	cin>>t;
//	while(t--){
//		work();
//	}
//	return 0;
//}
