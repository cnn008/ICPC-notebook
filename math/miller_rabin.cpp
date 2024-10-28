#include <bits/stdc++.h>
using namespace std;

#define ull uint64_t

ull modmul(ull a, ull b, ull m){return __int128_t(a)*b%m;}
ull modpow(ull b, ull e, ull mod){
	ull ans=1;
	for (; e; b=modmul(b,b,mod), e/=2) if(e&1) ans=modmul(ans,b,mod);
	return ans;
}
bool is_prime(ull n){
	if(n<2 || n%6%4!=1) return (n|1)==3;
	ull A[]={2,325,9375,28178,450775,9780504,1795265022},s=__builtin_ctzll(n-1),d=n>>s;
	for(ull a:A){ 
		ull p=modpow(a%n,d,n),i=s;
		while(p!=1 && p!=n-1 && a%n && i--) p=modmul(p,p,n);
		if(p!=n-1 && i!=s) return 0;
	}
	return 1;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	cout<<is_prime(n);
	return 0;
}