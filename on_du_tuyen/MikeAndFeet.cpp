#include <bits/stdc++.h>
#define task "main"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;

int n;
int a[maxn + 7], l[maxn + 7], r[maxn + 7], dp[maxn + 7];

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
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        l[i] = 1;
        r[i] = n;
    }

    std::stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            l[i] = s.top() + 1;
        }
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            r[i] = s.top() - 1;
        }
        s.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        int tmp = r[i] - l[i] + 1;
        dp[tmp] = std::max(dp[tmp], a[i]);
    }

    for (int i = n - 1; i >= 1; i--)
    {
        dp[i] = std::max(dp[i], dp[i + 1]);
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << dp[i] << " ";
    }

    return 0;
}
