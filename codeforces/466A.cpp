#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    if (m * a <= b)
        std::cout << n * a;
    else
        std::cout << (n / m) * b + std::min((n % m) * a, b);

    return 0;
}

