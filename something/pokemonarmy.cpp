#include <bits/stdc++.h>
#define ll long long

const int maxn = 3e5;

int t;
int n, a[maxn];

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

	std::cin >> t;
	while (t--){
        int q;
        std::cin >> n >> q;

        a[0] = a[n + 1] = 0;
        for (int i = 1; i <= n; i++) std::cin >> a[i];

        ll ans = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans += a[i];
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans -= a[i];
        }

        std::cout << ans << "\n";
        while (q--) {
            int l, r;
            std::cin >> l >> r;
            std::set<int> s;
            s.insert(l - 1);
            s.insert(l);
            s.insert(l + 1);
            s.insert(r - 1);
            s.insert(r);
            s.insert(r + 1);

            for (auto i : s)
                if (i != 0 && i <= n){
                    if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans -= a[i];
                    if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans += a[i];
                }

            std::swap(a[l], a[r]);

            for (auto i : s)
                if (i != 0 && i <= n){
                    if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans += a[i];
                    if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans -= a[i];
                }
            std::cout << ans << "\n";
        }
	}

	return 0;
}
