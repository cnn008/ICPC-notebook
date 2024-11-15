const ll INF = 1e18L + 5;
struct implicit_lichao_tree {
    struct node {
        ll a, b;
        ll nxt[2];
        node(ll v1=-INF, ll v2=-INF) {
        	a=v1; b=v2;
        	nxt[0] = nxt[1] = -1;
        }
        ll operator ()(ll x) {
            if (a == -INF) return -INF;
            return a*x + b;
        }
    };
    vector<node> st;
    void build() {
    	st.clear();
    	st.pb(node(-INF, -INF));
    }
    void new_node(ll id, ll o) {
    	st[id].nxt[o] = st.size();
    	st.pb(node(-INF, -INF));
    	ll idx = st[id].nxt[o];
    	st[idx].a = st[id].a;
    	st[idx].b = st[id].b;
    }
    void add(ll id, ll l, ll r, ll a, ll b) {
    	if(l == r) {
    		if(st[id](l) < a*l + b) {
    			st[id].a = a;
    			st[id].b = b;
    		}
    		return;
    	}
    	int mid = (l + r)/2;
    	if(r == l + 1) mid = l;
    	if(st[id].a > a) {
    		swap(st[id].a, a);
    		swap(st[id].b, b);
    	}
    	if(st[id](mid) < a*mid + b) {
    		swap(st[id].a, a);
    		swap(st[id].b, b);
    		if(st[id].nxt[0] == -1) new_node(id, 0);
    		add(st[id].nxt[0], l, mid, a, b);
    	}
    	else {
    		if(st[id].nxt[1] == -1) new_node(id, 1);
    		add(st[id].nxt[1], mid + 1, r, a, b);
    	}
    }
    ll get(ll id, ll l, ll r, ll pos) {
    	if(l == r) return st[id](pos);
    	int mid = (l + r)/2;
    	if(r == l + 1) mid = l;
    	if(pos <= mid) {
    		if(st[id].nxt[0] == -1) return st[id](pos);
    		return max(st[id](pos), get(st[id].nxt[0], l, mid, pos));
    	}
    	else {
    		if(st[id].nxt[1] == -1) return st[id](pos);
    		return max(st[id](pos), get(st[id].nxt[1], mid + 1, r, pos));
    	}
    }
} lt;