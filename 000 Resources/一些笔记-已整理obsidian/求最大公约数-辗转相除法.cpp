#include<bits/stdc++.h>
using namespace std;

// 使用欧几里得算法计算最大公约数（迭代版本）
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
	return 0;
}

