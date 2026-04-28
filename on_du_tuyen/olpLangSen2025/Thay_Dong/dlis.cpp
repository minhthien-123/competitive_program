#include <bits/stdc++.h>
#define task "dlis"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
std::string s;
int dp[maxn + 7][maxn + 7], f[maxn + 7][maxn + 7];

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
    std::cin >> s;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= i + 1; len++)
        {
            int u = i - len + 1;
            if (s[u] == '0' && len > 1)
            {
                continue;
            }
            int cnt = 1;
            if (i - len >= 0)
            {
                int j = i - len;
                int res = 0;
                for (int k = 1; k < len; k++)
                {
                    res = std::max(res, f[j][k]);
                }
                if (res > 0)
                    cnt = std::max(cnt, res + 1);
                for (int j = 0; j <= i - len; j++)
                {
                    if (dp[j][len] > 0)
                    {
                        int v = j - len + 1;
                        bool flag = false;
                        for (int t = 0; t < len; t++)
                        {
                            char c1 = s[v + t];
                            char c2 = s[u + t];
                            if (c1 < c2)
                            {
                                flag = true;
                                break;
                            }
                            if (c1 > c2)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                        {
                            cnt = std::max(cnt, dp[j][len] + 1);
                        }
                    }
                }
            }
            dp[i][len] = cnt;
            ans = std::max(ans, cnt);
        }
        for (int len = 1; len <= i + 1; len++)
        {
            if (i > 0)
            {
                f[i][len] = std::max(f[i - 1][len], dp[i][len]);
            }
            else
            {
                f[i][len] = dp[i][len];
            }
        }
    }

    std::cout << ans;

    return 0;
}