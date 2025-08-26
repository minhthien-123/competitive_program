#include <bits/stdc++.h>
#define task "lcis"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
int a[maxn + 7], b[maxn + 7], dp[maxn + 7], trace[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> m;
    for (int j = 1; j <= m; j++)
    {
        std::cin >> b[j];
    }

    for (int i = 1; i <= n; i++)
    {
        int tmp = 0, pos = -1;

        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                if (dp[j] < tmp + 1)
                {
                    dp[j] = tmp + 1;
                    trace[j] = pos;
                }
            }
            else if (a[i] > b[j])
            {
                if (dp[j] > tmp)
                {
                    tmp = dp[j];
                    pos = j;
                }
            }
        }
    }

    int ans = 0, pos = -1;

    for (int j = 1; j <= m; j++)
    {
        if (dp[j] > ans)
        {
            ans = dp[j];
            pos = j;
        }
    }

    std::vector<int> v;
    if (ans != 0)
    {
        while (pos != -1)
        {
            v.pb(b[pos]);
            pos = trace[pos];
        }
    }
    std::reverse(v.begin(), v.end());
    std::cout << ans << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

    return 0;
}