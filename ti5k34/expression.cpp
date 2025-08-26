#include <bits/stdc++.h>
#define task "expression"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;
const int maxs = 1e4;
const int tt   = 2e4;
const int inf  = 1e18;

struct expression
{
    int val;
    char c;
};

int n, s;
int a[maxn + 7];
expression dp[maxn + 7][6 * maxs + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    dp[1][a[1] + tt].val = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = -maxs; j <= maxs; j++)
        {
            if (j - a[i] >= -maxs && j - a[i] <= maxs && dp[i - 1][j - a[i] + tt].val == 1)
            {
                dp[i][j + tt].val = 1;
                dp[i][j + tt].c = '+';
            }
            else if (j + a[i] >= -maxs && j + a[i] <= maxs && dp[i - 1][j + a[i] + tt].val == 1)
            {
                dp[i][j + tt].val = 1;
                dp[i][j + tt].c = '-';
            }
            else
            {
                dp[i][j + tt].val = 0;
            }
        }
    }

    std::vector<char> ans;
    for (int i = n; i >= 2; i--)
    {
        ans.pb(dp[i][s + tt].c);
        if (dp[i][s + tt].c == '+')
        {
            s -= a[i];
        }
        else
        {
            s += a[i];
        }
    }
    std::reverse(ans.begin(), ans.end());

    for (auto i : ans)
    {
        std::cout << i;
    }

    return 0;
}
