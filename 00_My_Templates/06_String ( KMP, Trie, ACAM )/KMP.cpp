#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> getnext(const string &s){// 计算字符串 s 的前缀函数（next 数组） next[i] 表示 s[0..i] 的最长相等前后缀长度
	int len=s.size();
	vector<int> next(len);
	next[0]=0;// 单字符没有真前后缀
	for(int i=1;i<len;i++){
		int j=next[i-1];// 尝试扩展前一位置的前缀
		while(j>0&&s[i]!=s[j]) j=next[j-1]; // 回退直到匹配或到达起始位置
		if(s[i]==s[j]) j++;// 匹配成功，长度加 1
		next[i]=j;// 记录当前最长公共前后缀
	}
	return next;
}

vector<int> kmp(const string &s,const string &text){// KMP 匹配：返回模式串 s 在文本串 text 中所有匹配的起始下标（0-based）
	string cur=s+'#'+text;// 构造新串：模式串 + '#' + 文本串 '#' 是两个串中都不出现的分隔符，防止跨越模式串和文本串产生错误的前缀匹配
	int sz1=s.size();
	int sz2=text.size();
	vector<int> next=getnext(cur);// 计算整个串的前缀函数
	vector<int> ans;
	for(int i=sz1+1;i<=sz1+sz2;i++){// 如果以 cur[i] 结尾的子串与模式串完全匹配
		if(next[i]==sz1) ans.push_back(i-2*sz1);// 原始文本中的起始下标 = i - 模式串长度 - (模式串长度 + 1) + 1
	}// 简化：i - 2 * sz1
	return ans;
}
void solve(){
	string s,text;
	cin>>s>>text;
	vector<int> ans=kmp(s,text);
	for(auto i:ans) cout<<i<<" \n"[i==ans.size()-1];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T=1;
	//cin>>T;
	while(T--) solve();
}
