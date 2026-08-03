using i128 = __int128_t;
using u128 = __uint128_t;

ostream& operator << (ostream& os, i128 x){
	if(x < 0){
		os << '-';
		x = -x;
	}
	if(x > 9) os << x / 10;
	os << int(x % 10);
	return os;
}