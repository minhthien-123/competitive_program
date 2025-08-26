#include <bits/stdc++.h>
#define task "xdx"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

std::string a;
int n;

void sub1()
{
    for (int len = n; len >= 1; len--)
    {
        int cnt = 0;
        for (int i = len; i + len <= n; i++)
        {
            int l = i - len + 1;
            int r = i;
            int u = i + 1;
            int v = i + len;

            std::string s1, s2, t1, t2;
            for (int j = l; j <= r; j++)
            {
                s1 += a[j];
                s2 = a[j] + s2;
            }
            for (int j = u; j <= v; j++)
            {
                t1 += a[j];
                t2 = a[j] + t2;
            }

            if (s1 == s2 && t1 == t2 && s1 != t1)
            {
                cnt++;
            }
        }

        if (cnt != 0)
        {
            std::cout << 2 * len << " " << cnt;
            exit(0);
        }
    }

    std::cout << -1;
}

void sub2()
{
    bool dp[1007][1007];
    int pre[1007];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = false;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = true;
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
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (a[i] == '0');
    }

    for (int len = n / 2; len >= 1; len--)
    {
        int total = 2 * len;
        int cnt = 0;
        for (int l = 1; l + total - 1 <= n; l++)
        {
            int m = l + len - 1;
            int r = l + total - 1;
            if (!dp[l][m])
            {
                continue;
            }
            if (!dp[m + 1][r])
            {
                continue;
            }
            int d = pre[r] - pre[l - 1];
            if (d > 0 && d < total)
            {
                cnt++;
            }
        }
        if (cnt > 0)
        {
            std::cout << total << " " << cnt;
            return;
        }
    }

    std::cout << -1;
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

    std::cin >> a;
    n = a.size();
    a = " " + a;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 'a')
        {
            a[i] = '0';
        }
        else
        {
            a[i] = '1';
        }
    }

    if (n <= 200)
    {
        sub1();
    }
    else if (n <= 1000)
    {
        sub2();
    }
    else
    {
        sub2();
    }

    return 0;
}