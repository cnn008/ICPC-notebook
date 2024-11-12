#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll x){
	return (ull)(rng())%x;
}
ll modmul(ll a, ll b, ll M){
	ll ret=a*b-M*(ll)(1.L/M*a*b);
	return ret+M*(ret<0)-M*(ret>=(ll)M);
}
ll modpow(ll b, ll e, ll mod){
	ll ans=1;
	for (; e; b=modmul(b,b,mod), e/=2) if(e&1) ans=modmul(ans,b,mod);
	return ans;
}
bool isPrime(ll n){
	if(n<2 || n%6%4!=1) return (n|1)==3;
	ll A[]={2,325,9375,28178,450775,9780504,1795265022},s=__builtin_ctzll(n-1), d=n>>s;
	for(ll a:A){ 
		ll p=modpow(a%n,d,n),i=s;
		while(p!=1 && p!=n-1 && a%n && i--) p=modmul(p,p,n);
		if (p!=n-1 && i!=s) return 0;
	}
	return 1;
}
ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}
void pollard(ll x, vector<ll> &ans) {
    if(isPrime(x)){
        ans.push_back(x);
        return;
    }
    ll c=1;
    while(1){
        c=1+rand(x-1);
        auto f = [&](ll y) {
            ll res=modmul(y,y,x)+c;
            if(res>=x) res-=x;
            return res;
        };
        int B=100,len=1;
        ll y=2,g=1;
        while(g==1){
            ll z=y,zs=-1;
            for(int i=0; i<len; i++) z=f(z);
            int lft=len;
            while(g==1 and lft>0){
                zs=z;
                ll p=1;
                for(int i=0; i<B and i<lft; i++){
                    p=modmul(p,abs(z-y),x);
                    z=f(z);
                }
                g=gcd(p,x);
                lft-=B;
            }
            if(g==1){
                y=z;
                len<<=1;
                continue;
            }
            if(g==x){
                g=1;
                z=zs;
                while(g==1){
                    g=gcd(abs(z-y),x);
                    z=f(z);
                }
            }
            if(g==x) break;
            pollard(g,ans);
            pollard(x/g,ans);
            return;
        }
    }
}
vector<ll> factorize(ll x) {
    vector<ll> ans;
    for (ll p:{2,3,5,7,11,13,17,19}){
        while(x%p==0){
            x/=p;
            ans.push_back(p);
        }
    }
    if(x!=1) pollard(x, ans);
    sort(ans.begin(),ans.end());
    return ans;
}
vector< pair<ll, int> > factorize_pk(ll x){
	auto ps=factorize(x);
	ll last=-1,cnt=0;
	vector< pair<ll, int> > res;
		for(auto p:ps){
    	if(p==last) cnt++;
    	else{
        	if(~last) res.emplace_back(last,cnt);
        	last=p;
        	cnt=1;
    	}
	}
	if(cnt) res.emplace_back(last, cnt);
	return res;
}
vector<ll> get_all_divisors(ll n){
	auto pks=factorize_pk(n);
	vector<ll> res;
	function<void(int, ll)> gen=[&](int i, ll prod){
    	if(i==static_cast<int>(pks.size())) {
        	res.push_back(prod);
        	return;
    	}
    	ll cur_power=1;
    	for(int cur=0; cur<=pks[i].second; cur++){
        	gen(i+1, prod*cur_power);
        	cur_power*=pks[i].first;
    	}
	};
	gen(0,1LL);
	sort(res.begin(), res.end());
	return res;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	for(auto x:get_all_divisors(n)) cout<<x<<" ";
	return 0;
}