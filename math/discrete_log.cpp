// smallest x such that a**x = n (mod p) (1e9 contrainst)
int solve(int a, int n, int p){
	if(!n){
		int pr=a,cnt=1;
		while(1){
			if(cnt>=30) return -1;
			if(!pr) return cnt;
			pr=(pr*a)%p;
			cnt++;
		}	
	}
	int g=__gcd(a,p);
	if(n%g) return -1;
	int A=a;
	a/=g;n/=g;p/=g;A%=p;
	if(a==n) return 1;
	if(!A) return -1;
	if(n%__gcd(A,p)) return -1;
	unordered_map <int,int> mp;
	int s=sqrt(p);
	if(s*s==p) s--;
	int x=1,prod=a;
	for(int i=1; i<=s; i++) x=(x*A)%p;
	for(int i=1; i<=s+1; i++){
		prod=(prod*x)%p;
		if(!mp.count(prod)) mp[prod]=i;
	}
	prod=n;
	int ans=INT_MAX;
	for(int i=0; i<=s; i++){
		if(mp.count(prod)) ans=min(ans,mp[prod]*s-i);
		prod=(prod*A)%p;
	}
	if(ans==INT_MAX || a*powmod(A,ans)%p!=n) ans=-2;
	return ans+1;
}