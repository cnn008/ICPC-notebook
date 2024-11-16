#include "bits/stdc++.h"
using namespace std;
int exgcd(int a, int b, int& x, int& y) {
    if(!b){x=1;y=0;return a;}
    int x1,y1;
    int d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
int crt(int a1, int m1, int a2, int m2){
	int n1,n2;
	int d=exgcd(m1,m2,n1,n2);
	return (a1*n2*m2+a2*n1*m1+m1*m2*mod)%(m1*m2);
}
int crt(vector <pair <int,int> > &m){
	if((int)m.size()==1){
		if(!m[0].first) return m[0].second;
		return m[0].first;
	}
	int ans=crt(m[0].first,m[0].second,m[1].first,m[1].second);
	int prod=m[0].second*m[1].second;
	for(int i=2; i<(int)m.size(); i++) ans=crt(ans,prod,m[i].first,m[i].second),prod*=m[i].second;
	if(!ans) return prod;
	return ans;
}
vector <pair <int,int> > nw; 
vector <int> v; // prime numbers 1 -> sqrt
map <int,int> mp;
void fac(int x){
	for(auto p:v){
		if(x==1 || x<p) break;
		if(x%p==0){
			int cnt=1;
			while(x%p==0) x/=p,cnt*=p;
			mp[p]=max(mp[p],cnt);
		}
	}
	if(x>1 and !mp.count(x)) mp[x]=x;
}
void discrete(vector <pair <int,int> > &modu){ // non-prime : discrete to diffrent prime factors
	map <int,int> ck;
	for(auto [A,M]:modu){
		for(auto p:v){
			if(M==1 || M<p) break;
			if(M%p==0){
				int mpp=mp[p];
				if(M%mpp==0 and !ck.count(p)){
					ck[p]=1;
					nw.push_back({A%mpp,mpp});
					M/=mpp;
				}else while(M%p==0) M/=p;
			}
		}
		if(M>1){
			if(!ck.count(M) and mp[M]==M){
				ck[M]=1;
				nw.push_back({A%M,M});
			}
		}
	}
}