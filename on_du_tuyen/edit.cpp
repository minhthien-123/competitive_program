#include <bits/stdc++.h>
#define task "edit"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define ic std::pair<int, char>
#define sic std::pair<std::string, ic>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, t1, t2, t3;
std::string s1, s2;
int dp[maxn + 7][maxn + 7];

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

    std::cin >> s1 >> s2;
    std::cin >> t1 >> t2 >> t3;
    int m = s1.size();
    int n = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = inf;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = dp[i - 1][0] + t2;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] + t1;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
            }
            else
            {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + t3);
            }

            dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + t2);
            dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + t1);
        }
    }

    std::cout << dp[m][n] << "\n";

    int i = m, j = n;
    std::vector<sic> ans;

    while (i > 0 || j > 0)
    {
        if (i > 0 && j > 0 && s1[i] == s2[j] && dp[i][j] == dp[i - 1][j - 1])
        {
            i--;
            j--;
        }
        else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + t3)
        {
            ans.pb(sic("REP", ic(i, s2[j])));
            i--;
            j--;
        }
        else if (j > 0 && dp[i][j] == dp[i][j - 1] + t1)
        {
            ans.pb(sic("INS", ic(i, s2[j])));
            j--;
        }
        else
        {
            ans.pb(sic("DEL", ic(i, '0')));
            i--;
        }
    }

    std::reverse(ans.begin(), ans.end());

    int len = 0;
    for (auto i : ans)
    {
        if (i.fi == "REP")
        {
            std::cout << "REP " << i.se.fi + len << " " << i.se.se << "\n";
        }
        else if (i.fi == "INS")
        {
            std::cout << "INS " << i.se.fi + len + 1 << " " << i.se.se << "\n";
            len++;
        }
        else if (i.fi == "DEL")
        {
            std::cout << "DEL " << i.se.fi + len << "\n";
            len--;
        }
    }

    return 0;
}
