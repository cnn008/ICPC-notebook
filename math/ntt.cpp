const ll mod_ntt = 998244353;
const ll root = 15311432, root_1 = 469870224, root_pw = 1LL<<23;
ll powmod(ll a, ll b) {
    ll ans = 1;
    while(b) {
    	if(b & 1) ans = ans * a % mod_ntt;
    	a = a * a % mod_ntt;
    	b /= 2;
    }
    return ans;
}
void ntt(vector<long long>& a, bool inv) {
    ll n = a.size();
    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = (n>>1);
        for (; j&bit; bit>>=1) {j ^= bit;} j ^= bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (ll l = 2; l <= n; l <<= 1) {
        ll wl = inv ? root_1 : root;
        for (ll i = l; i < root_pw; i <<= 1) wl = ((wl*wl)%mod_ntt);
        for (ll i = 0; i < n; i += l) {
            ll w = 1;
            for (ll j = 0; j < l/2; j++) {
                ll u = a[i+j], v = ((a[i+j+l/2]*w)%mod_ntt);
                a[i+j] = ((u+v) < mod_ntt) ? (u+v) : (u+v-mod_ntt);
                a[i+j+l/2] = ((u-v) >= 0) ? (u-v) : (u-v+mod_ntt);
                w = (w*wl)%mod_ntt;
            }
        }
    }
    if (inv) {
        ll n_1 = powmod(n,mod_ntt-2);
        for (ll& i : a) i = (i*n_1)%mod_ntt;
    }
}
vector<long long> mul(vector<long long> const& a, vector<long long> const& b) {
    vector<long long> fa(a.begin(),a.end());
    vector<long long> fb(b.begin(),b.end());
    ll n = 1; 
    while(n < (int)a.size() + (int)b.size()) n <<= 1;
    fa.resize(n);  fb.resize(n); 
    ntt(fa,0); ntt(fb,0);
    for(ll i=0; i<n; i++) fa[i] = (fa[i]*fb[i])%mod_ntt;
    ntt(fa,1); 
    return fa;
}