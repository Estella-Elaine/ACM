template<class A, class B> string to_string(const pair<A, B>&);
string to_string(const string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; } 

template<class A> string to_string(const A& v) {
	string s = "";
	for (const auto& x : v) s += (sz(s) ? ", " : "{") + to_string(x);
	return s += "}";    
}

template<class A, class B> string to_string(const pair<A, B>& p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
void debug_out() { cerr << '\n'; }

template<class T, class... U>
void debug_out(const T& x, const U&... args) {
	cerr << ' ' << to_string(x);
	debug_out(args...);
}

#define sc(x) cerr << "\033[" << x << "m"
#define debug(...) sc(91 + (__LINE__ & 2)), cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__), sc(39)
