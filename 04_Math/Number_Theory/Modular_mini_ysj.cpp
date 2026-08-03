constexpr int mod = 998244353;
struct Z {
    i64 x;
    Z(i64 y = 0) : x(y % mod) { if (x < 0) x += mod; }
    Z operator+(const Z &o) const { return Z(x + o.x); }
    Z operator-(const Z &o) const { return Z(x - o.x); }
    Z operator*(const Z &o) const { return Z(x * o.x); }
};

Z power(Z a, int b) {
    Z res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}