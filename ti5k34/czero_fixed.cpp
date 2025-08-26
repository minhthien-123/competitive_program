#include <bits/stdc++.h>
#define task "czero"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 64;
const int inf  = 1e18;

int n, k, m;

int dp[maxn + 7][maxn + 7];

void init()
{
    for (int i = 0; i <= 64; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= 64; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}

void solve(int n, int k)
{
    int m = std::log2(n);
    int cnt = 0, ans = 0;
    std::vector<int> v;
    for (int i = 1; i <= m; i++)
    {
        if ((n >> (i - 1)) & 1)
        {
            v.pb(i);
        }
        if (i > k)
        {
            ans += dp[i - 1][cnt];
            cnt++;
        }
    }

    cnt = 1;
    m++;
    std::reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (m - cnt >= k)
        {
            int tmp = m - cnt - k;
            int cur = v[i] - 1 - tmp;
            if (cur >= 0)
            {
                ans += dp[v[i] - 1][cur];
            }
        }
        cnt++;
    }

    if (m - v.size() - 1 == k)
    {
        ans++;
    }

    std::cout << ans << "\n";
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    init();

    while (std::cin >> n >> k)
    {
        solve(n, k);
    }



    return 0;
}
