// given lines a_i x + b_i, query x find min val 
// x : [1,inf] 					can be [-inf,inf], inf = 1e9
struct LichaoTree{
	struct Line{
		// max b=-inf, min b=inf but somtimes 0
		int m,b,child[2];
		int operator()(int x){return m*x+b;}
		void swp(Line &l){
			swap(m,l.m);
			swap(b,l.b);
		}
	};
	vector <Line> val;
	inline void init(){
		val.emplace_back();
		val.back().child[0]=val.back().child[1]=-1;
	}
	inline int _child(int p, int d){
		if(val[p].child[d]==-1){
			val[p].child[d]=(int)val.size();
			init();
		}
		return val[p].child[d];
	}
	void clear(){
		val.clear();
		init();
	}
	// void insert(int l, int r, Line seg, int o=0){
	    // if(l+1==r){
	      	// if(seg(l)<val[o](l)) val[o].swp(seg);
	      	// return;
	    // }
    	// int mid=(l+r)>>1;
    	// if(val[o].m<seg.m) val[o].swp(seg);
    	// if(val[o](mid)>seg(mid)){
    		// val[o].swp(seg);
      		// insert(l,mid,seg,_child(o,0));
    	// }else insert(mid,r,seg,_child(o,1));
  	// }
  	// int query(int l, int r, int x, int o=0){
    	// if(l+1==r) return val[o](x);
    	// int mid=(l+r)>>1;
    	// if(x<mid) return min(val[o](x),query(l,mid,x,_child(o,0)));
    	// else return min(val[o](x),query(mid,r,x,_child(o,1)));
  	// }
  	void insert(int l, int r, Line seg, int o=0){
	    if(l+1==r){
	      	if(seg(a[l].y)>val[o](a[l].y)) val[o].swp(seg);
	      	return;
	    }
    	int mid=(l+r)>>1;
    	if(val[o].m<seg.m) val[o].swp(seg);
    	if(val[o](a[mid].y)<seg(a[mid].y)){
    		val[o].swp(seg);
      		insert(l,mid,seg,_child(o,0));
    	}else insert(mid,r,seg,_child(o,1));
  	}
  	int query(int l, int r, int x, int o=0){
    	if(l+1==r) return val[o](a[x].y);
    	int mid=(l+r)>>1;
    	if(x<mid) return max(val[o](a[x].y),query(l,mid,x,_child(o,0)));
    	else return max(val[o](a[x].y),query(mid,r,x,_child(o,1)));
  	}
}lc;