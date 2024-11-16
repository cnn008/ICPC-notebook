#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("arch=skylake")
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,fma,bmi,bmi2,popcnt,lzcnt,tune=native")

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#pragma GCC ivdep

__attribute__((always_inline)) void smin(int &a, int b) {a = a < b ? a : b;}
__attribute__((always_inline)) void smax(int &a, int b) {a = a > b ? a : b;}
#define _F __attribute__((always_inline))
_F int add(int a, int b) {return (a+=b)>=MOD?a-=MOD:a;}
_F int sub(int a, int b) {return (a-=b)<0?a+MOD:a;}
_F int mul(int a, int b) {return (a*1LL*b)%MOD;}
_F void set_add(int& a, int b) {if((a+=b)>=MOD) a-=MOD;}
_F void set_sub(int& a, int b) {if((a-=b)<0) a+=MOD;}
_F void set_mul(int& a, int b) {a=mul(a, b);}
_F int exp(int a, int b) {
    int ans=1;
    for(; b; b>>=1) {
        if(b&1) set_mul(ans, a);
        set_mul(a, a);
    }
    return ans;
}
#undef _F
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
#define IO_FAST 1
 
const int BufSize=1<<21;
struct FastIO
{
	char ibuf[BufSize+10],*p,*e;
	char obuf[BufSize+10],*q,stk[128];
 
#if IO_FAST
	FastIO(){q=obuf;}
	~FastIO(){fwrite(obuf,1,q-obuf,stdout);}
 
	int getChar()
	{
		if(p==e)p=ibuf,e=ibuf+fread(ibuf,1,BufSize,stdin);
		return p==e?EOF:*p++;
	}
	void putChar(int c)
	{
		if(q-obuf==BufSize)fwrite(obuf,1,BufSize,stdout),q=obuf;
		*q++=c;
	}
#else
	int getChar(){return getchar();}
	void putChar(int c){putchar(c);}
#endif
 
	FastIO& operator>>(char& c)
	{
		do{c=getChar();}while(isspace(c));
		return *this;
	}
	FastIO& operator>>(char* s)
	{
		*s=' ';
		while(isspace(*s))*s=getChar();
		while(!isspace(*s))*++s=getChar();
		*s=0;
		return *this;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
 
	FastIO& operator<<(char c)
	{
		putChar(c);
		return *this;
	}
	FastIO& operator<<(char* s)
	{
		while(*s)putChar(*s++);
		return *this;
	}
	FastIO& operator<<(const char* s)
	{
		while(*s)putChar(*s++);
		return *this;
	}
	template<typename T>
	FastIO& operator<<(T x)
	{
		int tp=0;
		if(x<0)x=-x,putChar('-');
		do{stk[++tp]=x%10,x/=10;}while(x);
		while(tp)putChar(stk[tp--]+'0');
		return *this;
	}
}IO;
// IO>>n, IO<<ans
// stress
: 100

gen.exe
brute.exe
stress.exe

fc /w arya.ans arya.out

if errorlevel 1 (exit)

goto 100