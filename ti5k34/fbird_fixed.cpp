#include <bits/stdc++.h>
#define task "fbird"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 20;
const int inf = 1e18;

int m, n, w;
int a[maxn + 7][maxn + 7];
int f[maxn + 7];
int ans = -1;

void solve(int pos, int sum)
{
    for (int i = 1; i <= m; i++)
    {
        if (a[i][pos] < f[pos - 1])
        {
            break;
        }

        f[pos] = a[i][pos];
        sum = sum + a[i][pos];
        if (w - sum >= f[pos] * (n - pos))
        {
            if (pos == n)
            {
                if (sum > w)
                {
                    continue;
                }
                /* tle
                ans = std::max(sum, ans);
                */
                // wa
                std::cout << sum;
                exit(0);
            }
            else
            {
                solve(pos + 1, sum);
            }
        }
        sum = sum - a[i][pos];
    }
}

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

    std::cin >> m >> n >> w;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (int j = 1; j <= n; j++)
    {
        std::vector<int> v;
        for (int i = 1; i <= m; i++)
        {
            v.pb(a[i][j]);
        }
        std::sort(v.begin(), v.end(), std::greater<int>());
        for (int i = 1; i <= n; i++)
        {
            a[i][j] = v[i - 1];
        }
    }

    /*for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }*/

    solve(1, 0);
    std::cout << ans << "\n";

    return 0;
}
