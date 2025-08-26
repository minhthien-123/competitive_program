#include <bits/stdc++.h>
#define task "cpair"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int a[maxn];
int n, l, r, ans = 0;


signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> l >> r;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }

    std::sort(a, a + n + 1);

    int j = 0, k = 0;
    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        if (j <= i) j = i + 1;
        if (k <= i) k = i + 1;

        while (j <= n && abs(a[j] - a[i]) < l) j++;
        while (k <= n && abs(a[k] - a[i]) <= r) k++;
        ans = ans + k - j;
    }

    std::cout << ans;

    return 0;
}
