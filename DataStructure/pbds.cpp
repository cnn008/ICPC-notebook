#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &it: a) {cin >> it;}
    ordered_set<int> me(begin(a), end(a));
    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 0) {
            me.insert(x);
        } else if(t == 1) {
            me.erase(x);
        } else if(t == 2) {
            auto it = me.find_by_order(x-1);
            cout << (it == end(me) ? -1 : *it) << '\n';
        } else if(t == 3) {
            cout << me.order_of_key(x+1) << '\n';
        } else if(t == 4) {
            auto it = me.upper_bound(x);
            cout << (it == begin(me) ? -1 : *prev(it)) << '\n';
        } else if(t == 5) {
            auto it = me.lower_bound(x);
            cout << (it == end(me) ? -1 : *it) << '\n';
        }
    }
}