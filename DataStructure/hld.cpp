// vi g[N + 5]
int head[N + 5], chain[N + 5];
int sz[N + 5], depth[N + 5], p[N + 5];
int arr[N + 5], pos[N + 5];
int curchain = 1, curpos = 1;
void dfs(int u, int par) {
	sz[u] = 1;
	if(par == -1) depth[u] = 1;
	for(auto v: g[u]) if(v != par) {
		p[v] = u;
		depth[v] = depth[u] + 1; 
		dfs(v, u);
		sz[u] += sz[v];
	}
}
void hld(int u, int par) {
	if(!head[curchain]) head[curchain] = u;
	chain[u] = curchain;
	pos[u] = curpos;
	arr[curpos] = u;
	curpos++;
	int nxt = 0;
	for(auto v: g[u]) if(v != par && sz[v] > sz[nxt]) nxt = v;
	if(nxt) hld(nxt, u);
	for(auto v: g[u])
		if(v != par && v != nxt) {curchain++; hld(v, u);}
}
void query(int u, int v) {
	while(chain[u] != chain[v]) {
		if(chain[u] > chain[v]) u = p[head[chain[u]]];
		else v = p[head[chain[v]]];
	}
	if(pos[u] < pos[v]) {}
	else {}
}