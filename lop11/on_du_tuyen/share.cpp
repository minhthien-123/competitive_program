#include <bits/stdc++.h>
#define task "share"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
ii a[maxn + 7];
int ans[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi;
        a[i].se = i;
    }

    std::sort(a + 1, a + n + 1);

    int cur = m;
    int pos = 1;

    while (pos <= n && cur > 0)
    {
        int tmp = n - pos + 1;
        int k = cur / tmp;
        if (k > a[pos].fi)
        {
            ans[a[pos].se] = a[pos].fi;
            cur -= a[pos].fi;
            pos++;
        }
        else
        {
            int x = k;
            int r = cur - x * tmp;
            for (int i = pos; i <= n; i++)
            {
                int y = 0;
                if (i - pos < r)
                {
                    y = 1;
                }
                ans[a[i].se] = x + y;
            }
            cur = 0;
        }
    }

    if (cur > 0)
    {
        std::cout << -1;
        exit(0);
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}