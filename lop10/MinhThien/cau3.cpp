#include <bits/stdc++.h>
#define task "cau3"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;

int n, s;
int a[maxn + 7], pre[maxn + 7], par[maxn + 7], f[maxn + 7], res[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     std::cout << pre[i] << " ";
    // }

    // pre[j] - pre[i - 1] <= s
    // pre[j] <= s + pre[i - 1]

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = std::upper_bound(pre + i, pre + n + 1, pre[i - 1] + s) - pre;
        //int tmp = i;
        par[i] = tmp;
    }

    for (int i = n; i >= 1; i--)
    {
        res[i] = res[par[i]] + n - i + 1;
        ans += res[i];
    }

    std::cout << ans;

    return 0;
}
