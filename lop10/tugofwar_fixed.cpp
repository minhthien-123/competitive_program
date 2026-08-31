#include <bits/stdc++.h>
#define task "tugofwar"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;
const int maxs = 1e6;
const int inf = 1e18;

int n, s = 0, t;
int a[maxn + 7], pre[maxn + 7];
int ans = 0;
bool res[maxn + 7], f[maxn + 7];

void Try(int i, int sum)
{
    if (sum > ans)
    {
        ans = sum;
        for (int j = 1; j <= n; j++)
        {
            res[j] = f[j];
        }
    }
    if (i > n)
    {
        return;
    }
    if (sum + pre[n] - pre[i - 1] <= ans)
    {
        return;
    }

    if (sum + a[i] <= t)
    {
        f[i] = 1;
        Try(i + 1, sum + a[i]);
        f[i] = 0;
    }
    Try(i + 1, sum);
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        s += a[i];
    }
    t = s / 2;
    Try(1, 0);
    std::vector<int> res1, res2;
    for (int i = 1; i <= n; i++)
    {
        if (res[i])
        {
            res1.pb(i);
        }
        else
        {
            res2.pb(i);
        }
    }
    std::cout << res1.size() << " " << res2.size() << "\n";
    for (int x : res1)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    for (int x : res2)
    {
        std::cout << x << " ";
    }
    return 0;
}
