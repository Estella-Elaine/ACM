/*
适用场景：求长度为 k 的滑动窗口内的最大值或最小值（经典题：洛谷 P1886，LeetCode 239）。
核心数据结构：std::deque（双端队列），队列里存的是元素的“下标”而不是“值”（方便判断元素是否滑出了窗口）。

记忆口诀：“去老（队首出界） -> 去弱（队尾维护单调性） -> 新人入队 -> 收集答案”
以下是求滑动窗口最大值的模板（维持队列单调递减）：
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res;     // 存储每个窗口的最大值
    deque<int> dq;       // 单调队列，存储元素的【下标】
    
    for (int i = 0; i < n; i++) {
        // 1. 维护队首（出界）：如果队首元素的下标已经不在当前窗口 [i-k+1, i] 内，弹出队首
        // 队首元素下标 == i - k 时，说明它刚刚滑出窗口
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // 2. 维护单调性（队尾卷王机制）：
        // 我们要求最大值，所以要把前面那些【比当前元素小】且【比当前元素旧】的元素都淘汰掉
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        
        // 3. 入队：将当前元素的下标加入队尾
        dq.push_back(i);
        
        // 4. 记录答案：当窗口完全形成后（即 i >= k - 1），队首元素就是当前窗口的最大值
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}