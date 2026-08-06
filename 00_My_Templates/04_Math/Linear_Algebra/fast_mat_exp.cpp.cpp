#include <iostream>
using namespace std;
using ll = long long;

const int MAXN = 110;       // 矩阵最大维度（2 就够，但保持通用）
const int MOD = 1e9 + 7;

int n;                      // 实际矩阵大小（此处固定为 2）
ll k;

struct Matrix {
    ll a[MAXN][MAXN];

    // 构造：全零
    Matrix() {
        for (int i = 0; i < MAXN; ++i)
            for (int j = 0; j < MAXN; ++j)
                a[i][j] = 0;
    }

    // 清空 n×n 区域
    void clear() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = 0;
    }

    // 置为单位矩阵
    void setIdentity() {
        clear();
        for (int i = 0; i < n; ++i)
            a[i][i] = 1;
    }

    // 矩阵乘法（对 MOD 取模）
    Matrix operator*(const Matrix& other) const {
        Matrix res;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < n; ++j) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

// 矩阵快速幂
Matrix fastPow(Matrix base, ll power) {
    Matrix res;
    res.setIdentity();
    while (power) {
        if (power & 1) res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;                     // 输入要求的项数（从 1 开始）

    if (k == 1 || k == 2) {
        cout << 1 << '\n';
        return 0;
    }

    n = 2;                        // 矩阵维度固定为 2

    // 构造转移矩阵 T = [[1,1],[1,0]]
    Matrix trans;
    trans.a[0][0] = 1;
    trans.a[0][1] = 1;
    trans.a[1][0] = 1;
    trans.a[1][1] = 0;

    // 计算 T^(k-2)
    Matrix result = fastPow(trans, k - 2);

    // 初始向量 [F(2), F(1)]^T = [1, 1]^T
    // 因此 F(k) = result[0][0] * 1 + result[0][1] * 1
    ll ans = (result.a[0][0] + result.a[0][1]) % MOD;
    cout << ans << '\n';

    return 0;
}
