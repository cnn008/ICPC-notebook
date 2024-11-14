// factorial up to 1e9
__attribute__((target("avx2"), optimize("O3,unroll-loops"))) int calc(int n){
  if (n >= mod) return 0;
  if (n * 2 > mod) {
    	int f = calc(mod - 1 - n);
    	if (n % 2 == 0) f = mod - f;
    	int res = 1;
    	for (int e = mod - 2; e; f = 1LL * f * f % mod, e >>= 1) if (e & 1) res = 1LL * res * f % mod;
    	return res;
  	}
  	int a[8] = {1, 1, 1, 1, 1, 1, 1, 1};
  	int b[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  	for (int i = 1; i <= n / 8; i++) {
    	for (int j = 0; j < 8; j++) a[j] = 1LL * a[j] * b[j] % mod;
    	for (int j = 0; j < 8; j++) b[j] += 8;
  	}
  	long long ans = 1;
  	for (int j = 0; j < 8; j++) ans = ans * a[j] % mod;
  	for (int x = n / 8 * 8 + 1; x <= n; x++) ans = ans * x % mod;
  	return ans;
}