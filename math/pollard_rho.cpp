#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll modmul(ll a, ll b, ll M){
	ll ret=a*b-M*(ll)(1.L/M*a*b);
	return ret+M*(ret<0)-M*(ret>=(ll)M);
}
ll modpow(ll b, ll e, ll mod){
	ll ans=1;
	for (; e; b=modmul(b,b,mod), e/=2) if(e&1) ans=modmul(ans,b,mod);
	return ans;
}
struct POLLARD_RHO{
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
	ll pollard(ll n) {
		auto f=[n](ll x){return modmul(x,x,n)+1;};
		ll x=0,y=0,t=30,prd=2,i=1,q;
		while(t++%40 || __gcd(prd,n)==1){
			if(x==y) x=++i,y=f(x);
			if((q=modmul(prd,max(x,y)-min(x,y),n))) prd=q;
			x=f(x),y=f(f(y));
		}
		return __gcd(prd,n);
	}
	vector<ll> factorize(ll n){
		if(n==1) return{};
		if(isPrime(n)) return{n};
		ll x=pollard(n);
		auto l=factorize(x),r=factorize(n/x);
		l.insert(l.end(),r.begin(),r.end());
		sort(l.begin(),l.end());
		return l;
	}
	vector< pair<ll, int> > factorize_pk(ll x){
    	auto ps=factorize(x);
    	ll last=-1,cnt=0;
    	vector< pair<ll, int> > res;
   		for(auto p:ps){
        	if(p==last) cnt++;
        	else{
            	if(last!=-1) res.emplace_back(last,cnt);
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
}polrho;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(auto d:polrho.get_all_divisors(n)) cout<<d<<" ";
	return 0;
}