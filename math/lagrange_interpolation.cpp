// f(0)->f(n) : find f(x)
int lagrange_interpolate(int n, int x){
	vector <int> pre(n+2),suf(n+2),invfac(n+2);
	pre[0]=x;
	for(int i=1; i<=n; i++) pre[i]=(pre[i-1]*(x-i))%mod;
	suf[n+1]=1;
	for(int i=n; i>=0; i--) suf[i]=(suf[i+1]*(x-i))%mod;
	invfac[0]=1;
	for(int i=1; i<=n; i++) invfac[i]=(invfac[i-1]*powmod(i,mod-2,mod))%mod;
	int ans=0;
	for(int i=0; i<=n; i++){
		int res;
		if(!i) res=g[i]*suf[i+1]%mod*invfac[n]%mod;
		else res=g[i]*pre[i-1]%mod*suf[i+1]%mod*invfac[i]%mod*invfac[n-i]%mod;
		if((n-i+1)&1) ans=(ans+res)%mod;
		else ans=(ans-res+mod)%mod;
	}
	return ans;
}