#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;
int n, l;
int a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> l;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);

    int r = std::max(a[1], l - a[n]) * 2;

    for (int i = 1; i <= n; i++){
        r = std::max(r, a[i + 1] - a[i]);
    }

    std::cout << std::fixed << std::setprecision(20) << r / 2.0;

    return 0;
}

