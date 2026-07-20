namespace fastIO {
	const int N = 1 << 15;
	char buf[N], *s = buf, *t = buf;

	inline char fetch() {
		if (s == t) {
			t = (s = buf) + fread(buf, 1, N, stdin);
			if (s == t) return EOF;
		}
		return *s++;
	}

	template<class T> inline void ReadOne(T& x) {
		bool sgn = 1;
		T a = 0;
		char c = fetch();
		for (; !isdigit(c); c = fetch()) sgn ^= (c == '-');
		for (; isdigit(c); c = fetch()) a = a * 10 + (c - '0');
		x = sgn ? a : -a;
	}

	void read() {}
	template<class T, class... U> void read(T& x, U&... args) {
		ReadOne(x);
		read(args...);
	}
} using fastIO::read; // close cin.tie(0)!