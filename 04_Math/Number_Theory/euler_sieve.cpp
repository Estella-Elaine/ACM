#include<bits/stdc++.h>
using namespace std;
using ll = long long;

using namespace std;

const int MAXN = 1e6+5;
vector<int> prime, minp, maxp;

void euler(int n = MAXN) {
    minp.resize(n + 1);
    maxp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = maxp[i] = i;
            prime.push_back(i);
        }
        for (auto j : prime) {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
            maxp[i * j] = maxp[i];
        }
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	euler();
	int T = 1;
//	cin >> T;
	// while(T--) work();
}