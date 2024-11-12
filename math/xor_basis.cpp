// check if any subset of a list have xor equal x
#include "bits/stdc++.h"
using namespace std;
struct xor_basis{
	int lg,sz;
	vector <int> basis;
	void init(int k){
		sz=0;
		lg=k;
		basis.clear();
		basis.resize(lg,-1);
	}
	void add(int x){
		for(int i=lg-1; i>=0; i--){
			if((x>>i)&1){
				if(basis[i]==-1){
					sz++;
					basis[i]=x;
					break;
				}else x^=basis[i];
			}
		}
		return;
	}
	bool query(int x){
		for(int i=lg-1; i>=0; i--) if((x>>i)&1 and basis[i]!=-1)x^=basis[i];
		return (x==0);
	}
}xb;
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    xb.init(30);
    xb.add(15);xb.add(182);xb.add(17);
    cout<<xb.query(168);
    return 0;
}