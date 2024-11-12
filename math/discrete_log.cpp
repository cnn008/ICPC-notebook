// https://dmoj.ca/problem/mathp9
// smallest x such that a**x = n (mod p) (1e9 contrainst)
#include "bits/stdc++.h"
using namespace std;
#define int long long
int a,n,p;
int powmod(int a, int k, int m){
   	int ans=1;
    while(k){
        if(k&1) ans=(ans*a)%m;
        a=(a*a)%m;
        k/=2;
    }
    return ans;
}
int inv(int a, int p){
	return powmod(a,p-2,p);
}
map <int,int> mp;
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    a=100;n=14;p=31;
	int b=sqrt(p),prod=1;
	mp[1]=0;
	for(int i=1; i<b; i++){
		prod=(prod*a)%p;
		mp[prod]=i;
	}
	int val=(prod*a)%p;
	prod=1;
	for(int i=1; i<=b; i++){
		if(powmod(a,i,p)==n){
			cout<<i;
			return 0;
		}
		prod=(prod*val)%p;
		int j=(n*inv(prod,p))%p;
		if(mp.count(j)){
			cout<<i*b+mp[j];
			return 0;
		}
	}
	cout<<"DNE";
    return 0;
}