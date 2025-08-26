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

int n, s = 0, sum = 0;
int a[maxn + 7], dp[maxs + 7];
bool trace[maxn + 7];

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
        s += a[i];
    }
    sum = s;
    s /= 2;

    for (int i = 1; i <= s; i++)
    {
        dp[i] = inf;
        for (int j = 1; j <= n; j++)
        {
            if (i >= a[j] && j > dp[i - a[j]])
            {
                dp[i] = j;
                break;
            }
        }
    }

    while (dp[s] > n)
        s--;
    int cnt = 0;
    while (s > 0)
    {
        trace[dp[s]] = 1;
        s -= a[dp[s]];
        cnt++;
    }

    std::cout << cnt << " " << n - cnt << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (trace[i])
        {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        if (!trace[i])
        {
            std::cout << i << " ";
        }
    }

    return 0;
}
