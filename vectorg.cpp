#include <bits/stdc++.h>
#define task "xn"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, k;
int a[maxn + 7][maxn + 7];
int dp[maxn + 7], b[maxn + 7];
int f[maxn + 7];
std::vector<std::vector<int>> g;

bool cmp(int x, int y)
{
    for (int i = 1; i <= m; i++)
    {
        if (a[x][i] != a[y][i])
            return a[x][i] < a[y][i];
    }
    return false;
}

bool check(int K)
{
    int h = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        int x = f[i];
        for (int j = 1; j < i; j++)
        {
            int y = f[j];
            bool flag = true;
            for (int t = 1; t <= m; t++)
            {
                if (a[y][t] > a[x][t])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        h = std::max(h, dp[i]);
        if (h > K)
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> b[j];
        }
        std::sort(b + 1, b + m + 1);
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = b[j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    std::sort(f + 1, f + n + 1, cmp);

    int l = 1, r = n, ans = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    k = ans;

    std::cout << k << "\n";

    int h = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        int x = f[i];
        for (int j = 1; j < i; j++)
        {
            int y = f[j];
            bool flag = true;
            for (int t = 1; t <= m; t++)
            {
                if (a[y][t] > a[x][t])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        h = std::max(h, dp[i]);
    }

    g.clear();
    g.resize(k + 1);
    for (int i = 1; i <= n; i++)
    {
        g[dp[i]].pb(f[i]);
    }

    int cnt = k - h;
    for (int i = 1; i <= h && cnt > 0; i++)
    {
        while (g[i].size() > 1 && cnt > 0)
        {
            int x = g[i].back();
            g[i].pop_back();
            g.pb(std::vector<int>{x});
            cnt--;
        }
    }

    for (int i = 1; i <= k; i++)
    {
        std::cout << g[i].size() << " ";
        for (int u : g[i])
        {
            std::cout << u << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
