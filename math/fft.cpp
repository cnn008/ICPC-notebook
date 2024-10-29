#include "bits/stdc++.h"
using namespace std;

const int LG=20;
const int N=1<<LG;
const double PI=acos(-1);

struct Complex{
    double r,i;
    Complex() : r(0), i(0) {}
    Complex(double t) : r(cos(t)), i(sin(t)) {}
    Complex(double r, double i) : r(r), i(i) {}
    const Complex operator + (const Complex &o) const {
        return Complex(r+o.r,i+o.i);
    }
    const Complex operator - (const Complex &o) const {
        return Complex(r-o.r,i-o.i);
    }
    const Complex operator * (const Complex &o) const {
        return Complex(r*o.r-i*o.i,r*o.i+i*o.r);
    }
    void operator /= (double d){
        this->r/=d;
        this->i/=d;
    }
};
int reverse(int mask){
    int r=0;
    for(int i=0; i<LG; i++) r|=((mask&(1<<i))>>i)<<(LG-i-1);
    return r;
}
void fft(vector<Complex> &a, bool inv=0){
    vector<Complex> b=a;
    for(int i=0; i<N; i++) b[i]=a[reverse(i)];
    for(int iter=0; iter<LG; iter++){
        int len=(1<<iter);
        Complex w((inv ? 1 : -1) * PI / len);
        int i=0,j=0;
        for(int cnt=(N>>(iter+1)); cnt--; ){
            i=j;
            j=i+len;
            Complex t(1.0,0.0);
            for(int l=len; l--; ){
                a[i]=b[i]+t*b[j];
                a[j]=b[i]-t*b[j];
                t=t*w;
                i++;
                j++;
            }
        }
        swap(a,b);
    }
    a=b;
    b=vector<Complex>();
    if(inv) for(int i=0; i<N; i++) a[i]/=N;
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector <Complex> a(N),b(N),c(N);
    fft(a);
	fft(b);
	for(int i=0; i<N; i++) c[i]=a[i]*b[i];
	fft(c,1);
	for(int i=0; i<N; i++) cout<<(int)(c[i].r+0.5)<<"\n";
    return 0;
}