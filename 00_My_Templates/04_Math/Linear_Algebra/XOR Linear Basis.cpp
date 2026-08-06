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

const int D = 61; // 支持 [0, 2^61)

struct LB{
	i64 b[D]; // b[i]: 最高位为 i 的基向量
	int cnt;  // 线性基的秩
	bool reduced; // 是否已经对角化

	LB(){
		clear();
	}

	void clear(){
		memset(b, 0, sizeof(b));
		cnt = 0;
		reduced = false;
	}

	bool insert(i64 x){ // 插入一个数，返回是否成功插入
		for(int i = D - 1; i >= 0; --i){
			if(!(x >> i & 1)) continue; // 这一位是 0，跳过

			if(!b[i]){ // 没有最高位为 i 的基向量
				b[i] = x;
				++cnt;
				reduced = false;
				return true;
			}

			x ^= b[i]; // 消掉 x 的最高位
		}

		// x 被消成 0，说明 x 可以由已有基向量表示
		return false;
	}

	bool contain(i64 x) const{ // 判断 x 能否被线性基表示
		for(int i = D - 1; i >= 0; --i){
			if(!(x >> i & 1)) continue;

			if(!b[i]) return false;

			x ^= b[i];
		}

		return true;
	}

	void rebuild(){ // 对角化
		for(int i = D - 1; i >= 0; --i){
			if(!b[i]) continue;

			for(int j = i - 1; j >= 0; --j){
				if((b[i] >> j) & 1){
					b[i] ^= b[j];
				}
			}
		}

		reduced = true;
	}

	i64 getMAX(i64 res = 0) const{
		// 求 res 异或线性基中的若干元素能够得到的最大值
		for(int i = D - 1; i >= 0; --i){
			if((res ^ b[i]) > res){
				res ^= b[i];
			}
		}

		return res;
	}

	i64 getMIN(i64 res) const{
		// 求 res 异或线性基中的若干元素能够得到的最小值
		for(int i = D - 1; i >= 0; --i){
			if((res ^ b[i]) < res){
				res ^= b[i];
			}
		}

		return res;
	}

	i64 getMinNotZero(){ // 求能够表示的最小非零值
		if(!cnt) return 0;

		if(!reduced) rebuild();

		for(int i = 0; i < D; ++i){
			if(b[i]) return b[i];
		}

		return 0;
	}

	i64 getKth(ull k){ // 求第 k 小，k 从 0 开始
		if(!reduced) rebuild();

		// cnt <= 61，所以 1ULL << cnt 不会溢出 ull
		if(k >= (1ULL << cnt)) return -1;

		vector<i64> v;

		for(int i = 0; i < D; ++i){
			if(b[i]){
				v.push_back(b[i]);
			}
		}

		i64 res = 0;

		for(int i = 0; i < sz(v); ++i){
			if((k >> i) & 1){
				res ^= v[i];
			}
		}

		return res;
	}

	void merge(const LB &other){ // 将另一个线性基合并进来
		for(int i = D - 1; i >= 0; --i){
			if(other.b[i]){
				insert(other.b[i]);
			}
		}
	}

	int rank() const{
		return cnt;
	}

	ull size() const{ // 能够表示出的不同异或值数量
		return 1ULL << cnt;
	}
};

void solve(){
	LB lb;

	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i){
		i64 x;
		cin >> x;
		lb.insert(x);
	}

	cout << lb.getMAX() << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	cin >> T;

	while(T--) solve();

	return 0;
}