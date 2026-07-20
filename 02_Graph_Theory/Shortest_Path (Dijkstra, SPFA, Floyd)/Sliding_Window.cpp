/*
适用场景：求满足某种条件的连续子数组（如求和大于等于 S 的最短子数组，或无重复字符的最长子串）。
核心思想：维护一个左指针 left 和右指针 right，像一条毛毛虫一样交替向前爬行。

这是一个非常通用的变长滑动窗口模板：
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int slidingWindowTemplate(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;  // 左指针
    int min_len = INT_MAX; // 记录最短长度，初始设为无穷大
    int window_sum = 0;    // 窗口内的具体状态
    for (int right = 0; right < n; right++) {
        // 1. 右指针主动吃进元素，更新窗口状态
        window_sum += nums[right];
        // 2. 判断窗口是否已经【达标/合法】（比如和 >= target 了）
        // 一旦达标，我们就尝试缩小窗口，看看能不能更短！
        while (window_sum >= target) {
            // 3. 此时窗口是【合法】的，赶紧记录当前的短度！
            // 注意：更新答案的代码在 while 里面！
            min_len = min(min_len, right - left + 1);
            // 记录完之后，尝试把左边的元素踢出去，看剩下的还达不达标
            window_sum -= nums[left]; 
            left++;                   
        }
    }
    // 如果 min_len 还是无穷大，说明压根没找到合法的窗口，返回 0
    return min_len == INT_MAX ? 0 : min_len;
}