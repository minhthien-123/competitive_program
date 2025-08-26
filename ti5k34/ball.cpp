#include <bits/stdc++.h>
#define task "ball"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int m, n, ans = 0;
int a[maxn], b[maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        std::cin >> b[i];
    }

    std::sort(a + 1, a + m + 1);
    std::sort(b + 1, b + n + 1);

    int l = 1, r = n / 2 + 1;
    int i = 0;
    while (i <= m && l <= n / 2 && r <= n) {
        if(b[l] >= a[i]) {
            i++;
            continue;
        }
        while(r <= n && b[r] <= a[i])
        {
            r++;
        }
        if (r <= n)
        {
            ans++;
        }
        l++;
        r++;
        i++;
    }
    std::cout << ans;

    return 0;
}