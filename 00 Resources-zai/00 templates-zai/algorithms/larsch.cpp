auto larsch = [&](auto&& self, int l, int r)->void {
	if (r - l <= 1) return; 
	int mid = (l + r + 1) / 2;
	folr(j, opt[l], opt[r]) update(j, mid);
	self(self, l, mid);
	folr(j, l + 1, mid) update(j, r);
	self(self, mid, r);
};