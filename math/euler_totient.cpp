#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=2e6;
const int inv2=499122177; 
template<int N>
struct Sieve{
private:
	int phi[N];
	vector <int> primes;
public:
	constexpr Sieve() {
		memset(phi, 0, sizeof phi);
		for (int i = 2; i < N; i++) {
			if (phi[i] == 0) {
				phi[i] = i;
				primes.push_back(i);
			}
			for (int j = 0; primes[j] * i < N; ++j) {
				phi[i * primes[j]] = primes[j];
				if (primes[j] == phi[i]) break;
			}
		}
		phi[1] = 1;
		for (int i = 2; i < N; i++) {
			int j = phi[i];
			if ((i / j) % j == 0) phi[i] = phi[i / j] * j;
			else phi[i] = phi[i / j] * (j - 1);
		}
		for (int i = 1; i < N; i++){
			 phi[i] += phi[i-1];
			 if(phi[i]>=mod) phi[i]-=mod;
		}
	}
	inline constexpr int operator[](std::size_t index) const
	{
		return phi[index];
	}
};
Sieve<N> phi;
unordered_map <long long,int> mp;
inline int sq(long long n) {
	return round(sqrt(n));
}
inline int rphi(long long n) {
	return (phi[n] - phi[n - 1] + mod) % mod;
}
int sum(long long n) {
	if (n < N) return phi[n];
	if (mp.count(n)) return mp[n];
	int y = sq(n);
	int x = sum(n / (y + 1));
	int pr = ((((n % mod) * ((n + 1) % mod)) % mod) * inv2) % mod;
	for (int i = 1; n / i > y; i++) {
		pr -= ((long long)rphi(i) * (n / i)) % mod;
		if (pr < 0) pr += mod;
	}
	for (int j = y; j > 1; j--) {
		int p = sum(n / j);
		pr -= ((long long)(p - x + mod) * j) % mod;
		if (pr < 0) pr += mod;
		x = p;
	}
	int val=pr+x;
	if(val>=mod) val-=mod;
	return mp[n]=val;
}
long long n;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	mp.max_load_factor(0.25);
	cin>>n;
	cout<<sum(n);
	return 0;
}     