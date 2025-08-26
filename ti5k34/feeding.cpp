#include <bits/stdc++.h>
#define task "feeding"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n;
int a[maxn], p[maxn];
int mn = LLONG_MAX, ans = 0;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;

    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i];

    for (int i = 1; i <= n; ++i) {
        mn = std::min(mn, p[i]);
        ans += mn * a[i];
    }

    std::cout << ans;

    return 0;
}
