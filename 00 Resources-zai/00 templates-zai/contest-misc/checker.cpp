void check(const string& data, const string& a, const string& b) {
	for (int tt = 0; ++tt; ) {
		system((data + ".exe > " + data + ".in").c_str());
		system((a + ".exe < " + data + ".in > " + a + ".out").c_str());
		system((b + ".exe < " + data + ".in > " + b + ".out").c_str());
		if (system(("fc " + a + ".out " + b + ".out").c_str())) {
			cerr << "wa on " << tt << '\n';
			return;
		}
		cerr << "ac on " << tt << '\n';
	}
}