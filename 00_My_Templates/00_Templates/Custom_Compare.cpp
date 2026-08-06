#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
using ull = unsigned long long; 
#define sz(a) int((a).size())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) (a).begin(), (a).end()
const int inf = (1 << 30);
const ll INF = (1ll << 60);
const double PI = acos(-1);

// 常见结构体排序写法
// 1.重载运算符
struct Node{
	int x, y, id;
	bool operator < (const Node& ot) const {
		if(x != ot.x) return x < ot.x;
		if(y != ot.y) return y > ot.y;
		return id < ot.id;
	}
};
void work(){
	vector<Node> a = {
		{2, 3, 1},
		{1, 5, 2},
		{2, 1, 3}
	};

	sort(all(a));

	for(auto [x, y, id] : a){
		cout << x << ' ' << y << ' ' << id << '\n';
	}
}

// 2.priority_queue: 符号相反
// 由于默认大根堆, operator < 里面“小于”的会被放下面
struct Node{
	int val, id;

	bool operator < (const Node& ot) const {
		if(val != ot.val) return val < ot.val; // val 大的优先
		return id > ot.id; // val 相同, id 小的优先
	}
};
priority_queue<Node> pq;

// 3.set 内置排序
struct Cmp{
	bool operator () (const Node& a, const Node& b) const {
		if(a.x != b.x) return a.x < b.x;
		if(a.y != b.y) return a.y > b.y;
		return a.id < b.id;
	}
};
set<Node, Cmp> st;

// 4.直接用 lambda
auto cmp = [](const Node& a, const Node& b) -> bool {
	if(a.x != b.x) return a.x < b.x;
	if(a.y != b.y) return a.y > b.y;
	return a.id < b.id;
};
set<Node, decltype(cmp)> st(cmp);

// 区别：
// sort / set：谁小谁在前
// return a.x < b.x;

// priority_queue：谁“大”谁在堆顶
// return a.x < b.x;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	work();
	return 0;
}