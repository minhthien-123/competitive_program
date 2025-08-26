#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

// số test
const ll test0 = 20;
const ll test1 = 15;
const ll test2 = 15;
// path
const std::string task = "C:\\c++\\srt\\";

void update1(ll x, ll val, ll bit1[]) {
    for (; x > 0; x -= x & (-x)) {
        bit1[x] = std::max(bit1[x], val);
    }
}

void update2(ll x, ll val, ll n, ll bit2[]) {
    for (; x <= n; x += x & (-x)) {
        bit2[x] = std::max(bit2[x], val);
    }
}

ll query1(ll x, ll n, ll bit1[]) {
    ll ans = 0;
    for (; x <= n; x += x & (-x)) {
        ans = std::max(ans, bit1[x]);
    }
    return ans;
}

ll query2(ll x, ll bit2[]) {
    ll ans = 0;
    for (; x > 0; x -= x & (-x)) {
        ans = std::max(ans, bit2[x]);
    }
    return ans;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (ll j = 1; j <= (test0 + test1 + test2); j++) {
        std::string tmp = task;
        if (j < 10) tmp += "0";
        tmp = tmp + std::to_string(j);
        CreateDirectory(tmp.c_str(), NULL);
        tmp = tmp + "\\srt";

        std::ofstream inp(tmp + ".inp");
        std::ofstream out(tmp + ".out");

        // khai báo
        ll n;

        // sinh test
        if (j <= test0) {
            n = rnd.next(1, 20);
        } else if (j <= test1) {
            n = rnd.next(1, 1000);
        } else {
            n = rnd.next(1, 50000);
        }

        ll a[n], f[n], g[n];
        ll bit1[n], bit2[n];
        std::vector<ll> v;

        for (int i = 1; i <= n; i++) {
            a[i] = rnd.next(-1000000000, 1000000000);
            v.push_back(a[i]);
        }

        std::sort(v.begin(), v.end());

        for (int i = 1; i <= n; i++) {
            a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        }

        for (int i = n; i >= 1; i--) {
            f[i] = 1 + query1(a[i] + 1, n, bit1);
            g[i] = 1 + query2(a[i] - 1, bit2);
            update1(a[i], f[i], bit1);
            update2(a[i], g[i], n, bit2);
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = std::max(ans, f[i] + g[i] - 1);
        }

        out << ans;

        inp.close();
        out.close();
    }

    return 0;
}
