#include <bits/stdc++.h>
#define task "palind3"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
std::string a;
bool dp[maxn + 7][maxn + 7], sp[maxn + 7][maxn + 7];
int d[maxn + 7];
std::vector<int> v;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> a;
    int n = a.size();
    a = " " + a;

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if (a[i] == a[j])
            {
                if (len == 2)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            if (dp[i][j])
            {
                sp[i][j] = 1;
            }
            else
            {
                for (int k = i + 1; k <= j - 1; k++)
                {
                    if (dp[i][k] && sp[k + 1][j])
                    {
                        sp[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (sp[i][j])
            {
                cnt++;
            }
        }
    }

    std::cout << cnt;

    return 0;
}
