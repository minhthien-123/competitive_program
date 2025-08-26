#include <bits/stdc++.h>
#define task "avm"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define ld long double

const int maxn = 1e5 + 7;

int n, k;
ld f[maxn], a[maxn];

bool check(ld x)
{
    memset(f, 0, sizeof(f));
    ld mn = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + (a[i] - x);
        if (i >= k)
        {
            if (f[i] - mn >= 0) return true;
            mn = std::min(mn, f[i - k + 1]);
        }
    }

    return false;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    ld l = 0, r = 1e9;
    int cnt = 0;
    while (cnt < 100)
    {
        ld mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
        cnt++;
    }

    std::cout << std::fixed << std::setprecision(2) << (l + r) / 2;

    return 0;
}
