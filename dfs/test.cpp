#include <bits/stdc++.h>
#define task "digit"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int gcd(int x, int y) {
    while (y != 0) {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

int res(int b) {
    int r = b;
    
    while (r % 2 == 0) r /= 2;
    while (r % 5 == 0) r /= 5;
    
    if (r == 1) return 0;
    
    int len = 1;
    int mod = 10 % r;
    while (mod != 1) {
        mod = (mod * 10) % r;
        len++;
    }
    
    return len;
}

char ans(int a, int b, int k) {
    //int integerPart = a / b;
    int rem = a % b;
    
    if (rem == 0) {
        rem *= 10;
        while (k > 0) {
            rem %= b;
            rem *= 10;
            --k;
        }
        return (rem / b) + '0';
    }

    int len = res(b);
    if (len == 0) {
        std::vector<int> d;
        rem *= 10;
        while (rem != 0 && d.size() < k) {
            d.pb(rem / b);
            rem = (rem % b) * 10;
        }
        if (k <= d.size()) {
            return d[k - 1] + '0';
        } else {
            return '0';
        }
    }

    std::vector<int> d;
    int pos = 0;
    rem *= 10;
    while (pos < len) {
        d.push_back(rem / b);
        rem = (rem % b) * 10;
        ++pos;
    }
    
    int cr = (k - 1) % len;
    return d[cr] + '0';
}

int t;

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);
    
    std::cin >> t;
    
    while (T--) {
        int a, b, k;
        std::cin >> a >> b >> k;
        std::cout << ans(a, b, k) << '\n';
    }
    
    return 0;
}
