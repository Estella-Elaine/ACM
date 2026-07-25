#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int D=51; // 最大二进制位数
struct LB{
	ll b[D];// b[i] 表示最高位为 i 的线性基
	LB(){memset(b,0,sizeof(b));}
	void insert(ll x){				// 向线性基中插入一个数 x
		for(int i=D-1;i>=0;i--){
			if(!(x>>i&1)) continue;// 如果 x 的第 i 位是 0，跳过
			if(!b[i]){			// 当前位没有基向量，直接插入
				b[i]=x;
				break;
			}
			x^=b[i]; 		// 否则用 b[i] 消去 x 的最高位，继续下一位
		}
	}
	 // 高斯消元：将线性基转化为「简化阶梯形」（对角化）
    // 执行后每个 b[i] 只会保留第 i 位为 1，其余低位均为 0
	void rebuild(){
		for(int i=D-1;i>=0;i--){
			if(!b[i]) continue;// 没有这个基，跳过
			for(int j=i-1;j>=0;j--){
				if(b[i]>>j&1) b[i]^=b[j];
			}
		}
	}
	
	ll getMAX(){ // 求最大异或和
		rebuild(); // 先对角化
		ll res=0;
		for(int i=D-1;i>=0;i--){
			if(b[i]) res^=b[i];// 将消元后的所有基向量全部异或起来
		}
		return res;
	}
};

void solve(){
	LB lb;
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		lb.insert(t);// 将所有数插入线性基
	}
	cout<<lb.getMAX()<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T=1;
	cin>>T;
	while(T--) solve();
}
