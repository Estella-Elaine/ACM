struct Node {
	Node* p = 0, * l = 0, * r = 0;
	int id, c = 1;
	ll v, sum;
	bool rev = false;

	Node(int id, ll v): id(id), v(v), sum(v) {}
	static int GetC(const Node* u) { return u ? u->c : 0; }
	static ll GetSum(const Node* u) { return u ? u->sum : 0; }

	void reverse() { // 1. push other tags before reverse children 2. pull if necessary
		rev ^= 1;
		swap(l, r);
	}

	void push() {
		if (rev) {
			if (l) l->reverse();
			if (r) r->reverse();
			rev = false;
		}
	}

	void pull() {
		if (l) l->p = this;
		if (r) r->p = this;
		c = GetC(l) + GetC(r) + 1;
		sum = GetSum(l) ^ GetSum(r) ^ v;
	}
};

template<class T, bool rooted = false> class LinkCutTree { 
private:
	static bool IsRoot(const T* v) { return !v->p or (v->p->l != v and v->p->r != v); }

	static void rotate(T* v) {
		T* u = v->p;
		u->push();
		v->push();
		v->p = u->p;
		if (v->p) {
			if (v->p->l == u) v->p->l = v;
			else if (v->p->r == u) v->p->r = v;
		}
		if (v == u->l) {
			u->l = v->r;
			v->r = u;
		} else {
			u->r = v->l;
			v->l = u;
		}
		u->pull();
		v->pull();
	}

	static void splay(T* v) {
		if (!v) return;
		while (!IsRoot(v)) {
			T* u = v->p;
			if (!IsRoot(u)) rotate(((u->l == v) ^ (u->p->l == u)) ? v : u);
			rotate(v);
		}
	}

	static void reverse(T* v) {
		splay(v);
		v->reverse();
	}

	static void access(T* v) {
		T* r = 0, * u = v;
		function<void(T*)> PushPath = [&](T* u) {
			if (u->p) PushPath(u->p);
			u->push();
		};
		PushPath(u);
		while (u) {
			splay(u);
			u->r = r;
			u->pull();
			r = u;
			u = u->p;
		}
		splay(v);
		assert(!v->p);
	}

	vector<T*> nodes;
public:
	template<class... U>
	int emplace(U&&... args) {
		int id = sz(nodes);
		nodes.push_back(new T(id, args...));
		return id;
	}

	void crown(int i) {
		assert(!rooted);
		T* v = nodes[i];
		access(v);
		reverse(v);
	}

	void modify(int i, ll x) {
		T* v = nodes[i];
		splay(v);
		v->v = x;
		v->pull();
	}

	T* expose(int i, int j) {
		assert(!rooted);
		T* v = nodes[i], * u = nodes[j];
		access(v);
		reverse(v);
		access(u);
		return u;
	}

	bool link(int i, int j) {
		if (i == j) return false;
		T* v = nodes[i], * u = nodes[j];
		if (rooted) {
			splay(v);
			if (v->p or v->l) return false;
		} else crown(i);
		access(u);
		if (v->p) return false;
		v->p = u;
		return true;
	}

	bool cut(int i, int j) {
		if (i == j) return false;
		T* v = nodes[i], * u = nodes[j];
		access(u);
		splay(v);
		if (v->p != u) {
			if (rooted) return false;
			swap(u, v);
			access(u);
			splay(v);
			if (v->p != u) return false;
		}
		v->p = 0;
		return true;
	}
};