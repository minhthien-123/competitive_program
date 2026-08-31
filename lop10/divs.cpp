#include <bits/stdc++.h>
#define task
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int solve(int n) {
    std::vector<int> divs = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m = divs.size();
    int ans = 0;

    for (int mask = 1; mask < (1 << m); ++mask) {
        int cnt = 0;
        int tmp = 1;

        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                tmp = lcm(tmp, divs[i]);
                cnt++;
            }
        }

        int res = n / tmp;

        if (cnt % 2 == 1) {
            ans += res;
        } else {
            ans -= res;
        }
    }

    return n - ans;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int n;
    std::cin >> n;
    std::cout << solve(n);

    return 0;
}
