#include <bits/stdc++.h>
#define task ""
#define ull unsigned long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

ull a, n, m, t;

ull power(ull a, ull b, ull m) {
    if (!b) return 0;
    ull x = power(a, b / 2, m);
    if (b % 2 == 0)
        return x * x % m;
    else
        return (x * x + a) % m;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //freopen("power.inp", "r", stdin);
    //freopen("power.out", "w", stdout);

    std::cin >> t;
    while (t--){
        std::cin >> n >> a >> m;
        std::cout << power(a, n, m);
    }

    return 0;
}
