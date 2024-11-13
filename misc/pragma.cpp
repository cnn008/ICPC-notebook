#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("arch=skylake")
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,fma,bmi,bmi2,popcnt,lzcnt,tune=native")

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

__attribute__((always_inline)) void smin(int &a, int b) {a = a < b ? a : b;}
__attribute__((always_inline)) void smax(int &a, int b) {a = a > b ? a : b;}

int read(){
	int res=0;bool bo=false;char c;
	while (((c=getchar())<'0'||c>'9')&&c!='-');
	if (c=='-') bo=true;
	else res=c-'0';
	while ((c=getchar())>='0'&&c<='9') res=(res<<3)+(res<<1)+c-'0';
	return bo?~res+1:res;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    assert(l<=r);
    return uniform_int_distribution<int> (l,r)(rng);
}