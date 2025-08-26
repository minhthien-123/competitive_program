#include <bits/stdc++.h>
#define task "bt2"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, k;
std::string dp[maxn + 7][maxn + 7][maxn + 7];

std::string sum(std::string a, std::string b)
{
    int i = a.size() - 1, j = b.size() - 1;
    int tmp = 0;
    std::string res = "";
    while (i >= 0 || j >= 0 || tmp)
    {
        int s = tmp;
        if (i >= 0)
        {
            s += a[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            s += b[j] - '0';
            j--;
        }
        tmp = s / 10;
        res.pb((char)('0' + s % 10));
    }
    std::reverse(res.begin(), res.end());
    return res;
}

void solve(int n, int k)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int p = 0; p <= k; p++)
            {
                dp[i][j][p] = "0";
            }
        }
    }
    dp[0][0][0] = "1";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int p = 0; p <= k; p++)
            {
                if (dp[i][j][p] == "0")
                {
                    continue;
                }

                if (std::max(p, j + 1) <= k && j + 1 <= n)
                {
                    dp[i + 1][j + 1][std::max(p, j + 1)] = sum(dp[i + 1][j + 1][std::max(p, j + 1)], dp[i][j][p]);
                }

                if (j > 0)
                {
                    dp[i + 1][j - 1][p] = sum(dp[i + 1][j - 1][p], dp[i][j][p]);
                }
            }
        }
    }

    std::string res = dp[n][0][k];

    if (res.size() > 10)
    {
        std::cout << res.substr(0, 5) << "..." << res.substr(res.size() - 5, 5) << "\n";
    }
    else
    {
        std::cout << res << "\n";
    }
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

    while (std::cin >> n >> k)
    {
        if (n % 2 != 0)
        {
            std::cout << 0 << "\n";
        }
        else
        {
            solve(n, k);
        }
    }

    return 0;
}
