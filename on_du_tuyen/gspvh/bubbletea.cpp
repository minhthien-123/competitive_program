#include <bits/stdc++.h>
#define task "bubbletea"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod +1) / 2;
const int tt = 2000;

int n;
int a[maxn + 7], d[maxn + 7];
int mx = -inf, mn = inf;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
        mn = std::min(mn, a[i]);
        d[a[i] + tt]++;
    }

    int cnt = 0;
    for (int i = mn; i <= mx; i++)
    {
        int tmp = std::min(d[i], d[i + 1]);
        cnt += tmp;
        d[i + tt] -= tmp;
        d[i + 1 + tt] -= tmp;

        cnt += d[i + tt] / 2;
        d[i + tt] %= 2;
    }

    std::cout << n - cnt;

    return 0;
}
