/*
topo_sort
*/
vector<vector<int>> g(n);
vector<int> deg(n, 0);

vector<int> q;
folr(u, 0, n - 1) if (!deg[u]) q.push_back(u);
folr(ind, 0, sz(q) - 1) {
	int u = q[ind];
	for (int v : g[u]) if (!--deg[v]) q.push_back(v);
}