#include<bits/stdc++.h>
using namespace std;
using i64 = long long; 
using ull = unsigned long long; 
#define sz(a) int((a).size())
#define pii pair<int, int>
#define pll pair<i64, i64>
#define all(a) (a).begin(), (a).end()
const int inf = (1 << 30);
const i64 INF = (1ll << 60);
const double PI = acos(-1);

// 返回 模式串p 在 文本串s 中所有匹配的 0-base 起点
vector<int> kmpMatch(const string& s, const string& p){
	int n = sz(p);
	vector<int> nxt(n);

	// nxt[i]: p[0...i] 的最长相等真前后缀长度
	for(int i = 1, j = 0; i < n; ++i){
		while(j && p[i] != p[j]) j = nxt[j - 1];
		if(p[i] == p[j]) ++j;
		nxt[i] = j;
	}

	vector<int> pos;
	for(int i = 0, j = 0; i < sz(s); ++i){
		while(j && s[i] != p[j]) j = nxt[j - 1];
		if(s[i] == p[j]) ++j;
		if(j == n){
			pos.push_back(i - n + 1);
			j = nxt[j - 1]; // 继续匹配，支持重叠
		}
	}
	return pos;
}

void work(){
	string s, p;
	cin >> s >> p;

	// 题设1. 在 文本串s 中查找 模式串p 的所有出现位置
	vector<int> pos = kmpMatch(s, p);

	// 题设2. 只需判断是否有匹配
	bool flag = !kmpMatch(s, p).empty();

	cout << sz(pos) << '\n';
	for(int i = 0; i < sz(pos); ++i){
		cout << pos[i] << " \n"[i == sz(pos) - 1]; // 0-base
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	cin >> T;
	while(T--) work();
	return 0;
}