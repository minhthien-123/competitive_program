#include <bits/stdc++.h>
#define task "delarr"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    // std::freopen(task".inp", "r", stdin);
    // std::freopen(task".out", "w", stdout);

    int n;
    std::cin >> n;
    int a[n + 7], s = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        s += a[i];
    }

    std::sort(a + 1, a + n + 1);
    int i = 1, j = n, d = 0;
    while (s != 0)
    {
        if (s < 0)
            s -= a[i++];
        else
            s -= a[j--];
        d++;
    }

    std::cout << d;

    return 0;
}
