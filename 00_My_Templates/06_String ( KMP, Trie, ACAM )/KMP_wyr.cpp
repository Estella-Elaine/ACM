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

void work(){
	string s, p;
	cin >> s >> p;

	vector<int> nxt(sz(p)); // nxt[i]: p[0...i] 的最长相等真前后缀长度
	for(int i = 1, j = 0; i < sz(p); ++i){
		while(j && p[i] != p[j]) j = nxt[j - 1];
		if(p[i] == p[j]) ++j;
		nxt[i] = j;
	}

	vector<int> pos;
	for(int i = 0, j = 0; i < sz(s); ++i){
		while(j && s[i] != p[j]) j = nxt[j - 1];
		if(s[i] == p[j]) ++j;
		if(j == sz(p)){
			pos.push_back(i - sz(p) + 1); // 0-base 匹配起点
			j = nxt[j - 1]; // 继续寻找，可处理重叠匹配
		}
	}

	cout << sz(pos) << '\n';
	for(int i = 0; i < sz(pos); ++i){
		cout << pos[i] << " \n"[i == sz(pos) - 1];
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