#include <bits/stdc++.h>
#define task "DUMBBELL"
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
const int inv  = (mod + 1) / 2;

int n, w;
int a[maxn + 7];
std::vector<int> base = {20, 15, 10, 5, 2, 1};

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
        a[i] += a[i - 1];
    }
    std::cin >> w;

    int ans = inf;

    for (int i = 0; i <= n; i++)
    {
        if (a[i] > w)
        {
            continue;
        }

        int tmp = w - a[i], cur = tmp, res = 0;
        for (int j : base)
        {
            if (cur == 0)
            {
                break;
            }
            res += cur / j;
            cur %= j;
        }

        ans = std::min(ans, (n - i) + res);
    }

    std::cout << ans << '\n';

    return 0;
}
