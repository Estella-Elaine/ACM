#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    //用vector<pair<int,int>> (可以保持插入顺序，允许重复)
    //而不是map<int,int> (自动按键排序，键不能重复) (如果要按值排序 需要先转换成vector)
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    //经典sort函数写法
    sort(a.begin(),a.end(),
    [](const pair<int,int>& a,const pair<int,int>& b) {
        return a.second < b.second;
    });

    int cnt=0;
    int last_end=-1;

    for(int i=0;i<n;i++){
        // 如果当前活动的开始时间 >= 上一个选择活动的结束时间
        if(a[i].first >= last_end){
            cnt++;
            last_end=a[i].second;
        }
    }
    cout<<cnt<<endl;
    return 0;
}