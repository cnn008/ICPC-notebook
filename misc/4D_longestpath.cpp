// longest path such that (i->j) <-> (ai<=aj,bi<=bj,ci<=cj,di<=dj)
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
const int N=5e4+5;
const int mod=1e9+7;
int n,dp[N];
vector < tuple <int,int,int,int> > mahiru;
vector <int> compress;
struct Data{
	int x,y,z,id;
};
vector <Data> v;
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
void cdq(int l, int r){
	if(l+1==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid);
	vector <Data> tmp,cecilia,fake;
	for(int i=mid; i<r; i++) fake.push_back(v[i]);
	sort(v.begin()+mid,v.begin()+r,[&](Data a, Data b){
		return a.x<b.x;
	});
	for(int i=l; i<mid; i++) fw.fake_update(v[i].y,v[i].z);
	for(int i=mid; i<r; i++) fw.fake_get(v[i].y,v[i].z);
	fw.init_nodes();
	int a=l,b=mid;
	while(a<mid and b<r){
		if(v[a].x<=v[b].x) fw.update(v[a].y,v[a].z,dp[v[a].id]),tmp.push_back(v[a]),cecilia.push_back(v[a++]);
		else dp[v[b].id]=max(dp[v[b].id],fw.get(v[b].y,v[b].z)+1),cecilia.push_back(v[b++]);
	}
	while(a<mid) tmp.push_back(v[a]),cecilia.push_back(v[a++]);
	while(b<r) dp[v[b].id]=max(dp[v[b].id],fw.get(v[b].y,v[b].z)+1),cecilia.push_back(v[b++]);
	for(int i=l; i<mid; i++) v[i]=tmp[i-l];
	for(int i=mid; i<r; i++) v[i]=fake[i-mid];	
	fw.clear();
	vector <Data> ().swap(tmp);
	cdq(mid,r);
	for(int i=l; i<r; i++) v[i]=cecilia[i-l];
	vector <Data> ().swap(cecilia);
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fw.init(N+N);
	cin>>n;
	for(int i=1; i<=n; i++){
		dp[i]=1;
		int x,y,z,t;
		cin>>x>>y>>z>>t;
		compress.push_back(z);
		compress.push_back(t);
		mahiru.push_back({x,y,z,t});
	}
	sort(compress.begin(),compress.end());
	compress.erase(unique(compress.begin(),compress.end()),compress.end());
	sort(mahiru.begin(),mahiru.end(),[&](tuple <int,int,int,int> a, tuple <int,int,int,int> b){
		if(get<0>(a)==get<0>(b)){
			if(get<1>(a)==get<1>(b)){
				if(get<2>(a)==get<2>(b)) return get<3>(a)<get<3>(b);
				return get<2>(a)<get<2>(b);
			}
			return get<1>(a)<get<1>(b);
		}
		return get<0>(a)<get<0>(b);
	});
	for(auto [i,x,y,z]:mahiru) v.push_back({x,y,z,(int)v.size()+1});
	for(auto &[x,y,z,id]:v){
		y=lower_bound(compress.begin(),compress.end(),y)-compress.begin()+1;
		z=lower_bound(compress.begin(),compress.end(),z)-compress.begin()+1;
	}
	cdq(0,n);
	cout<<*max_element(dp+1,dp+n+1);
    return 0;
}