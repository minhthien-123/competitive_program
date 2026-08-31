#include <bits/stdc++.h>
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

std::map<int, int> prime(int n) {
    std::map<int, int> f;
    while (n % 2 == 0) {
        f[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            f[i]++;
            n /= i;
        }
    }
    if (n > 2) {
        f[n]++;
    }
    return f;
}

int pow(int x, int y) {
    int result = 1;
    while (y > 0) {
        if (y % 2 == 1)
            result *= x;
        x *= x;
        y /= 2;
    }
    return result;
}

int solve(int n) {
    std::map<int, int> m = prime(n);
    int ans = 1;

    for (auto i : m) {
        int p = i.fi, e = i.se;
        int add = (e + 1) / 2 * 2;
        ans *= pow(p, add);
    }

    return ans;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n;
    std::cin >> n;
    std::cout << solve(n) << '\n';

    return 0;
}
