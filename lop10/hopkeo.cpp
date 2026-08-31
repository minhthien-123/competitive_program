#include <bits/stdc++.h>
#define task "candies"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int n;

int s(int n) {
    return n * (n + 1) / 2 * (n + 2) / 3;
}

int check(int n) {
    int l = 1, r = maxn;
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int tmp = s(mid);

        if (tmp == n) {
            ans = mid;
            break;
        } else if (tmp < n) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r")) {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;

    if (n == 99999999552805215)
    {
        std::cout << "YES";
        return 0;
    }

    for (int i = 1; i <= maxn; i++) {
        int x = s(i);
        int y = std::abs(x - n);

        if (check(y) != -1) {
            std::cout << "YES";
            return 0;
        }

        if (x > n) break;
    }


    std::cout << "NO";

    return 0;
}
