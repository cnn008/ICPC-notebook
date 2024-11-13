#include <bits/stdc++.h>
#ifndef DEBUG_H
#define DEBUG_H
using namespace std;
// Define __print for various data types
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V> &x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template<typename T>
void __print(const T &x) { int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"; }
void _print() { cerr << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << " "; _print(v...); }

#ifndef ONLINE_JUDGE
#define cebug(x...) do { cerr << "[" << #x << "] = "; _print_debug(x); } while (0)
#else
#define cebug(x...)
#endif

template <typename... Args>
void _print_debug(Args... args);

template <typename T>
void _print_debug_helper(const T &t) {
    __print(t);
}
template <typename T, typename... Args>
void _print_debug(T t, Args... args) {
    _print_debug_helper(t);
    if (sizeof...(args)) {
        cerr << " ";
        _print_debug(args...);
    } else {
        _print();
    }
}
#endif // DEBUG_H
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector <int> v={1,5,2,4,3};
	set <int> s={1,2,3,4};
	pair <int,int> p={1,2};
	cebug(p);cebug(v);cebug(s);
	return 0;
}