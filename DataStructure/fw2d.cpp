struct Fenwick2D{
    #define gb(x) (x)&(-x)
    vector<vector<int>> nodes,bit;
    vector <int> record,vis;
    int sx;
    void init(int _sx){
        sx = _sx;
        nodes.resize(sx + 1);
        bit.resize(sx + 1);
        vis.resize(sx+1,0);
    }
    void init_nodes(){
        for(int i : record){
            sort(all(nodes[i]));
            nodes[i].resize(unique(all(nodes[i])) - nodes[i].begin());
            bit[i].resize(sz(nodes[i]) + 1);
        }
    }
	void clear(){
		for(auto i:record) nodes[i].clear(),bit[i].clear(),vis[i]=0;
		record.clear();
	}
    void fake_update(int x, int y){
        for(; x <= sx; x += gb(x)){
        	if(!vis[x]){
        		vis[x]=1;
        		record.push_back(x);
        	}
            nodes[x].push_back(y);
        }
    }
    void fake_get(int x, int y){
        for(; x; x -= gb(x)){
        	if(!vis[x]){
        		vis[x]=1;
        		record.push_back(x);
        	}
            nodes[x].push_back(y);
        }
    }
    void update(int x, int yy, int val){
        for(; x <= sx; x += gb(x))
            for(int y = lower_bound(all(nodes[x]), yy) - nodes[x].begin() + 1; y <= sz(nodes[x]); y += gb(y))
                bit[x][y] = max(bit[x][y], val);
    }
    int get(int x, int yy){
        int res = 0;
        for(; x; x -= gb(x))
            for(int y = upper_bound(all(nodes[x]), yy) - nodes[x].begin(); y > 0; y -= gb(y))
                res = max(res, bit[x][y]);
        return res;
    }
}fw;