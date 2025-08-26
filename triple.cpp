#include <bits/stdc++.h>
#define task "triple"
#define int long long

const int maxn = 5e3 + 7;

int n, ans = -1;
int a[maxn], f[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    f[n + 1] = 0;
    for (int i = n; i >= 1; i--)
        f[i] = std::max(f[i + 1], a[i]);

    for (int i = 1; i <= n - 2; i++)
        for (int j = i + 1; j <= n - 1; j++)
            if (a[i] < a[j] && a[j] < f[j + 1])
                ans = std::max(ans, a[i] + a[j] + f[j + 1]);


    std::cout << ans;

    return 0;
}
