int par[N + 5];
stack<pair<int, int>> his;
void init(int n) {
	while(!his.empty()) his.pop();
	for(int i=1; i<=n; i++) par[i]  = -1;
}
int find(int u) {
	return (par[u] < 0 ? u : find(par[u]));
}
bool merge(int u, int v) {
	u = find(u); v = find(v);
	if(u == v) return false;
	if(abs(par[u]) < abs(par[v])) swap(u, v);
	his.push({v, par[v]}); 
	his.push({u, abs(par[u])});
	par[u] += par[v];
	par[v] = u;
	return true; 
}
void rollback() {
	if(his.empty()) return;
	ii u = his.top(); his.pop();
	par[u.fi] = u.se;
	ii v = his.top(); his.pop();
	par[v.fi] = v.se;
}