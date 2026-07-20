template<class Cap, class Cost, Cap InfCap = numeric_limits<Cap>::max(), Cost InfCost = numeric_limits<Cost>::max() / 4>
struct CostNet {
	int n;
	vector<int> head, to, nxt;
	vector<Cap> cap;
	vector<Cost> price;

	CostNet(int n): n(n), head(n, -1) {}

	void AddDir(int u, int v, Cap c, Cost w) {
		nxt.push_back(head[u]);
		head[u] = sz(to);
		to.push_back(v);
		cap.push_back(c);
		price.push_back(w);
	}

	void add(int u, int v, Cap c, Cost w) {
		AddDir(u, v, c, w);
		AddDir(v, u, 0, -w);
	}

	pair<Cap, Cost> flow(int s, int t, Cap tot = InfCap) {
		vector<Cost> h(n, InfCost);
		h[s] = 0;
		folr(it, 1, n) folr(u, 0, n - 1) for (int i = head[u]; ~i; i = nxt[i]) if (cap[i]) h[to[i]] = min(h[to[i]], h[u] + price[i]);
		Cost cost = 0;
		Cap res = 0;
		for (; tot; ) {
			priority_queue<pair<Cost, int>> pq;
			vector<Cost> dis(n, InfCost);
			vector pre(n, -1);
			dis[s] = 0;
			pq.emplace(0, s);
			while (sz(pq)) {
				auto [d, u] = pq.top();
				pq.pop();
				if (-d != dis[u]) continue;
				Cost off;
				for (int i = head[u]; ~i; i = nxt[i]) if (cap[i] and (off = dis[u] + price[i] + h[u] - h[to[i]]) < dis[to[i]]) {
					dis[to[i]] = off;
					pq.emplace(-off, to[i]);
					pre[to[i]] = i;
				}
			}
			if (pre[t] == -1) break;
			folr(u, 0, n - 1) if (dis[u] != InfCost) h[u] += dis[u];
			Cap aug = tot;
			for (int i = pre[t]; ~i; i = pre[to[i ^ 1]]) aug = min(aug, cap[i]);
			for (int i = pre[t]; ~i; i = pre[to[i ^ 1]]) {
				cap[i] -= aug;
				cap[i ^ 1] += aug;
			}
			tot -= aug;
			res += aug;
			cost += aug * h[t];
		}
		return {res, cost};
	}
};