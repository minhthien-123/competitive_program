#include <bits/stdc++.h>
#define task "daycs"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

std::string a, b;
int m, n;
int dp[maxn + 7][maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> a >> b;
    m = a.size();
    n = b.size();
    a = " " + a;
    b = " " + b;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int l = 1; l <= std::min(m, n); l++)
    {
        std::unordered_set<std::string> s;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dp[i][j] >= l)
                {
                    s.ins(a.substr(i - l + 1, l));
                }
            }
        }

        for (auto str : s)
        {
            int cnta = 0, cntb = 0;
            int pos = 0;

            while (true)
            {
                pos = a.find(str, pos);
                if (pos == std::string::npos)
                {
                    break;
                }
                cnta++;
                pos++;
                if (cnta > 1)
                {
                    break;
                }
            }
            if (cnta != 1)
            {
                continue;
            }

            pos = 0;
            while (true)
            {
                pos = b.find(str, pos);
                if (pos == std::string::npos)
                {
                    break;
                }
                cntb++;
                pos++;
                if (cntb > 1)
                {
                    break;
                }
            }
            if (cntb != 1)
            {
                continue;
            }

            std::cout << l;
            exit(0);
        }
    }

    std::cout << -1;

    return 0;
}
