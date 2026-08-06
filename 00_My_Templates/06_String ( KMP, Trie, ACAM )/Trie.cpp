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

const int N = 3000000 + 5;
const int M = 65;

int trie[M][N], mc[N], pos;
int mp[128];

void work(){
	int n, q;
	cin >> n >> q;

	for(int i = 1; i < M; ++i){
		fill(trie[i], trie[i] + pos + 1, 0);
	}
	fill(mc, mc + pos + 1, 0);
	pos = 0;

	auto add = [&](const string& s) -> void {
		int x = 0;
		for(auto c : s){
			int id = mp[int(c)];
			if(!trie[id][x]){
				trie[id][x] = ++pos;
			}
			x = trie[id][x];
			++mc[x];
		}
	};

	auto query = [&](const string& s) -> int {
		int x = 0;
		for(auto c : s){
			int id = mp[int(c)];
			if(!trie[id][x]){
				return 0;
			}
			x = trie[id][x];
		}
		return mc[x];
	};

	string s;
	for(int i = 1; i <= n; ++i){
		cin >> s;
		add(s);
	}

	while(q--){
		cin >> s;
		cout << query(s) << '\n';
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int id = 0;
	for(int c = 32; c <= 126; ++c){
		if(isalpha(c) || isdigit(c)){
			mp[c] = ++id;
		}
	}

	int T;
	cin >> T;
	while(T--) work();
	return 0;
}