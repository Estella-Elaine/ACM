#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    // 最小堆（优先队列 
    priority_queue<int, vector<int>, greater<int>> minn;
    
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        minn.push(x);
    }
    
    int ans = 0;
    // 当堆中还有至少两堆时
    while (minn.size() > 1) {
        int first=minn.top(); 
		minn.pop();
		
        int second=minn.top(); 
		minn.pop();
        
        int cost=first+second;
        ans+=cost;
        
        minn.push(cost);
    }
    cout<<ans<<endl;
    return 0;
}
