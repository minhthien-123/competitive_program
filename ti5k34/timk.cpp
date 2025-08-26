#include <bits/stdc++.h>
#define task "timk"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;

int n, m, k;

std::vector<ii> factorize(int n) {
    std::vector<ii> res;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            res.pb({i, cnt});
        }
    }
    if (n > 1) {
        res.pb({n, 1});
    }
    return res;
}

int solve(int n, int k) {
    int ans = 0;
    int tmp = k;
    while (tmp <= n) {
        ans += n / tmp;
        tmp *= k;
    }
    return ans;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r")) {
        std::freopen("timk.inp", "r", stdin);
        std::freopen("timk.out", "w", stdout);
    }

    std::cin >> n >> m;

    if (m == 0) {
        std::cout << 0;
        return 0;
    }

    std::vector<ii> res = factorize(m);

    if (res.empty()) {
        std::cout << 0;
        return 0;
    }

    int ans = LLONG_MAX;
    for (ii i : res) {
        ans = std::min(ans, solve(n, i.fi) / i.se);
    }

    std::cout << ans;

    return 0;
}