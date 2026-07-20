mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> T rnd() { return uniform_int_distribution<T>()(rng); } 
template<class T> T rnd(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }

struct Treap {
private:
	Treap* ls = 0, * rs = 0, * fa = 0;
	ll val, sum;
	int cnt = 1, rev = 0;

	void update() {
		if (ls) ls->fa = this;
		if (rs) rs->fa = this;
		cnt = 1 + GetCnt(ls) + GetCnt(rs);
		sum = val + GetSum(ls) + GetSum(rs);
	}

	void push() {
		if (rev) {
			swap(ls, rs);
			reverse(ls);
			reverse(rs);
			rev = false;
		}
	}
public:
	Treap(ll v): val(v), sum(v) {}
	static int GetCnt(Treap* u) { return u ? u->cnt : 0; }
	static int GetSum(Treap* u) { return u ? u->sum : 0; }
	static void reverse(Treap* u) { if (u) u->rev ^= 1; }

	static Treap* GetRoot(Treap* u) {
		while (u->fa) u = u->fa;
		return u;
	}

	static Treap* merge(Treap* u, Treap* v) {
		if (!u or !v) return u ? u : v;
		Treap* w = rnd(0, u->cnt + v->cnt - 1) < u->cnt ? u : v;
		w->push();
		if (w == u) u->rs = merge(u->rs, v);
		else v->ls = merge(u, v->ls);
		w->update();
		return w;
	}

	static pair<Treap*, Treap*> split(Treap* u, int k) {
		if (k <= 0) return {0, u};
		if (!u or k >= u->cnt) return {u, 0};
		u->push();
		Treap* w;
		if (k <= GetCnt(u->ls)) {
			tie(w, u->ls) = split(u->ls, k);
			if (w) w->fa = 0;
			u->update();
			return {w, u};
		} else {
			tie(u->rs, w) = split(u->rs, k - GetCnt(u->ls) - 1);
			if (w) w->fa = 0;
			u->update();
			return {u, w};
		}
	}

	void output() {
		debug((ll)this, (ll)ls, (ll)rs, (ll)fa, val, sum, cnt, rev);
	}
};