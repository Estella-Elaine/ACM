#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18; // 极大值防溢出

struct Edge {
    int v;
    ll w;
};

// n: 节点数, s: 起点
// g: 邻接表存图 vector<Edge> g[N]
// dist: 最短路距离数组
// 返回值：如果存在从起点可达的负环，返回 true；否则返回 false
bool spfa(int n, int s, const vector<vector<Edge>>& g, vector<ll>& dist) {
    dist.assign(n + 1, INF);
    vector<int> cnt(n + 1, 0);      // cnt[i] 记录从起点 s 到 i 的最短路包含几条边
    vector<bool> in_q(n + 1, false); // in_q[i] 记录节点 i 当前是否在队列中
    queue<int> q;
    
    // 1. 初始化起点
    dist[s] = 0;
    q.push(s);
    in_q[s] = true;
    
    // 2. 队列 BFS 松弛
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_q[u] = false; // 出队后标记为不在队列中
        
        // 遍历所有从 u 出发的边
        for (const auto& edge : g[u]) {
            int v = edge.v;
            ll w = edge.w;
            
            // 尝试松弛
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1; // 经过的边数 + 1
                
                // 核心判负环逻辑：抽屉原理！
                // 如果一条最短路经过了 >= n 条边（即包含超过 n 个点），必然存在负环！
                if (cnt[v] >= n) return true; // 发现负环，立刻终止！
                
                // 如果 v 被更新了，且 v 不在队列中，就把它加进队列
                // (因为 v 变小了，它有可能去更新它的邻居)
                if (!in_q[v]) {
                    q.push(v);
                    in_q[v] = true;
                }
            }
        }
    }
    return false; // 队列空了也没触发负环，说明没有负环
}

/*
SPFA 在随机图上跑得飞快，复杂度近似 O(k⋅E)（k 是一个小常数）。
但是！只要出题人稍微有点良心（或者坏心眼），他可以故意构造一种“菊花图”或“网格图”，把 SPFA 诱导进队列反复横跳，它的复杂度会瞬间退化成最原始的 O(V×E)，导致必定超时（TLE）！
只要图里没有负权边：死都不要用 SPFA！必须用 Dijkstra！
如果图里有负权边，或者题目明确要求判断负环：你没有选择，只能硬着头皮用这套 SPFA 板子，并祈祷出题人没有卡你的数据。
*/