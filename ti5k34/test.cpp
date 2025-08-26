#include <bits/stdc++.h>
#define task "base"
#define int long long

int n, b, c;
const std::string dg = "0123456789abcdefghijklmnopqrstuvwxyz";

bool check(int num, int b, int c) {
    std::string str;
    int tmp = num;

    while (tmp > 0) {
        str = dg[tmp % b] + str;
        tmp /= b;
    }

    for (char dig : str) {
        int cur;
        if (dig >= '0' && dig <= '9')
        {
            cur = dig - '0';
        }
        else if (dig >= 'a' && dig <= 'z')
        {
            cur = dig - 'a' + 10;
        }
        else
        {
            return false;
        }

        if (cur >= c)
        {
            return false;
        }
    }

    return true;
}

int count(int limit, int b, int c) {
    int count = 0;
    for (int i = 1; i <= limit; i++) {
        if (!check(i, b, c)) {
            count++;
        }
    }
    return count;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task".inp", "r")) {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> b >> c;

    int l = 1, r = 1e6;
    while (count(r, b, c) < n) {
        r *= 2;
    }

    // Binary search chính xác
    while (l < r) {
        int mid = l + (r - l) / 2;
        int tmp = count(mid, b, c);

        if (tmp >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    std::cout << l;
    return 0;
}
