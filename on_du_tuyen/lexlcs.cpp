#include <bits/stdc++.h>
#define task "lexlcs"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define ic std::pair<int, char>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

std::string a, b, lex, lcs;
int m, n;
ic dp1[maxn + 7][maxn + 7], dp2[maxn + 7][maxn + 7];

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

    std::cin >> a >> b;
    m = a.size();
    n = b.size();

    a = " " + a;
    b = " " + b;

    for (int i = m; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            if (a[i] == b[j])
            {
                dp1[i][j] = ic(dp1[i + 1][j + 1].fi + 1, a[i]);
            }
            else
            {
                if (dp1[i + 1][j].fi > dp1[i][j + 1].fi)
                {
                    dp1[i][j] = dp1[i + 1][j];
                }
                else if (dp1[i + 1][j].fi < dp1[i][j + 1].fi)
                {
                    dp1[i][j] = dp1[i][j + 1];
                }
                else
                {
                    if (dp1[i + 1][j].se > dp1[i][j + 1].se)
                    {
                        dp1[i][j] = dp1[i + 1][j];
                    }
                    else
                    {
                        dp1[i][j] = dp1[i][j + 1];
                    }
                }
            }
        }
    }

    // std::cout << dp1[1][1].fi << "\n";

    int i = 1, j = 1;

    while (dp1[i][j].fi > 0)
    {
        lcs += dp1[i][j].se;
        while (a[i] != dp1[i][j].se)
        {
            i++;
        }
        while (b[j] != dp1[i][j].se)
        {
            j++;
        }
        i++;
        j++;
    }

    std::cout << lcs << "\n";

    for (int i = m + 1; i >= 1; i--)
    {
        for (int j = n + 1; j >= 1; j--)
        {
            if (i == m + 1 && j == n + 1)
            {
                dp2[i][j] = ic(0, ' ');
            }
            else if (i == m + 1)
            {
                dp2[i][j] = ic(dp2[i][j + 1].fi + 1, b[j]);
            }
            else if (j == n + 1)
            {
                dp2[i][j] = ic(dp2[i + 1][j].fi + 1, a[i]);
            }
            else if (a[i] == b[j])
            {
                dp2[i][j] = ic(dp2[i + 1][j + 1].fi + 1, a[i]);
            }
            else
            {
                ic f1 = ic(dp2[i + 1][j].fi + 1, a[i]);
                ic f2 = ic(dp2[i][j + 1].fi + 1, b[j]);
                if (f1.fi < f2.fi || (f1.fi == f2.fi && f1.se < f2.se))
                {
                    dp2[i][j] = f1;
                }
                else
                {
                    dp2[i][j] = f2;
                }
            }
        }
    }

    // std::cout << dp2[1][1].fi << "\n";

    i = 1, j = 1;

    while (dp2[i][j].fi > 0)
    {
        char tmp = dp2[i][j].se;
        lex += tmp;
        if (i <= m && j <= n && a[i] == b[j])
        {
            i++;
            j++;
        }
        else if (i <= m && a[i] == tmp)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    std::cout << lex;

    return 0;
}
