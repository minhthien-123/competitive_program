#include <bits/stdc++.h>
#define task "tmark"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

struct tmark
{
    int t, x, y;
} a[maxn + 7];

bool cmp(tmark x, tmark y)
{
    return x.t - x.x - x.y > y.t - y.x - y.y;
}

int n;
int t = 0, x = 1, y = 1;
int ans = 0;

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
        std::cin >> a[i].t >> a[i].x >> a[i].y;
    }

    std::sort(a + 1, a + n + 1, cmp);

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << a[i].t << " " << a[i].x << " " << a[i].y << "\n";
    }*/

    int i = 1;
    while (i <= n)
    {
        int cost = 0;
        if (a[i].x > x)
        {
            cost += a[i].x - x;
            x = a[i].x;
        }
        if (a[i].y > y)
        {
            cost += a[i].y - y;
            y = a[i].y;
        }
        if (cost <= t)
        {
            t -= cost;
            ans++;
            t += a[i].t;
        }

        //std::cout << i << " " << t << " " << cost << "\n";

        i++;
    }

    std::cout << ans;

    return 0;
}

// t = t - (a[i].x - x + a[i].y - y) + a[i].t
// t = t + x + y + a[i].t - a[i].x - a[i].y