// ax+by=d
// ton tai n0 khi d chia het gcd(a,b)
template<typename T>
T extgcd(T a, T b, T &x, T &y) {
    T g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}