mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> T rnd() { return uniform_int_distribution<T>()(rng); } 
template<class T> T rnd(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }
