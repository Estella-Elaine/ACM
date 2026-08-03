/* 码风说明：
请按我的 C++ 竞赛码风生成代码：
1.使用我给出的固定头文件和 `work()` + 多测 `T` 框架，不要省略测试组数 `T`，除非我明确说明单测。
2.保持我的空格和括号风格：`for(int i = 1; i <= n; ++i){}`、`if(cond){}`，运算符两侧留空，缩进使用 tab 风格。
3.输出统一使用 `cout`，避免混用 `printf`，除非特殊需要。
4.代码注释尽量少，只在关键算法步骤处简短说明。整体代码保持竞赛模板风格，简洁但可读。
5.变量名尽量短，通常控制在 1~3 个字符，最长不超过 5 个字符，必要时可以在函数命名时使用中间下划线；但函数名、结构体名、核心 lambda 名需要有可读性，例如 `check`、`calc`、`dfs`、`comb`、`lucas`、`exgcd`。
6.优先使用 `vector`、`string`、`queue`、`priority_queue`、`set` 等 STL，只有空间很大或性能必要时才使用全局 C 数组。
7.对于维护最小值/最大值，习惯使用模板常量初始化： `int mn = inf, mx = -inf;`  `ll mn = INF, mx = -INF;`
其中 `inf` 和 `INF` 来自固定模板： `const int inf = (1 << 30);`  `const ll INF = (1ll << 60);`
变量类型需要和数据范围匹配，并且使用前要确保它们已经被有效更新，或者通过 `cnt`、`empty()`、布尔标记等方式判断是否存在有效元素。
8.代码逻辑优先写在 `work()` 内，辅助逻辑优先使用 lambda 表达式而不是全局函数。
9.对于需要频繁提前返回的特判，习惯在 `work()` 内定义局部 lambda，例如：
`auto report = [&](int x) -> void { cout << x << '\n'; };`
或如果只输出无解：
`auto report = [&]() -> void { cout << 0 << '\n'; };`
然后使用 `return report(0);` 或 `return report();` 简化代码。

附上我的头文件板子：
*/

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

void work(){
} 

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) work();
    return 0;
}