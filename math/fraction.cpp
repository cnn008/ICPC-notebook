#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) { return (a == b) ? 0 : ((a < b) ? -1 : 1); }

struct Fraction {
    int a, b;
    Fraction() {
        a = 0;
        b = 1;
    }
    Fraction(int _a, int _b) {
        a = _a;
        b = _b;
        norm();
    }
    Fraction(int x) {
        a = x;
        b = 1;
    }
    Fraction operator + (const Fraction& other) const {
        return Fraction(a * other.b + b * other.a, b * other.b);
    }
    Fraction operator - (const Fraction& other) const {
        return Fraction(a * other.b - b * other.a, b * other.b);
    }
    Fraction operator * (const Fraction& other) const {
        return Fraction(a * other.a, b * other.b);
    }
    Fraction operator / (const Fraction& other) const {
        assert(other.a != 0);
        return Fraction(a * other.b, b * other.a);
    }
    int cmp(Fraction other) const {
        return ::cmp(a * other.b, b * other.a);
    }

#define Comp(x) bool operator x (Fraction q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
#undef Comp
    void norm() {
        if (b < 0) {
            a = -a;
            b = -b;
        }
        if (a == 0) b = 1;
        else {
            int g = __gcd(llabs(a), llabs(b));
            a /= g;
            b /= g;
        }
    }
};
istream& operator >> (istream& cin, Fraction& p) {
    cin >> p.a >> p.b;
    return cin;
}
ostream& operator << (ostream& cout, Fraction& p) {
    cout << p.a << '/' << p.b;
    return cout;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Fraction ans;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		Fraction a;
		cin>>a;
		ans=ans+a;
	}
	cout<<ans;
	return 0;
}