#include <bits/stdc++.h>
#define int long long
#define task "czero"
#define ii std::pair<int, int>
#define fi first
#define se second

const int maxn = 32;

int c[maxn + 7][maxn + 7];
int dp[maxn + 7][maxn + 7][2];
int n, k, a, b, x = 1, ans = 0, cnt = 1;
std::string s;

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

int solve(int pos, int d, bool flag, int len)
{
    if (pos == len)
    {
        if (d == a)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (dp[pos][d][flag] != -1)
    {
        return dp[pos][d][flag];
    }

    int lim;
    if (flag)
    {
        lim = (int)s[pos] - '0';
    }
    else
    {
        lim = 1;
    }

    int res = 0;
    for (int digit = 0; digit <= lim; digit++)
    {
        int nd = d + (digit == 1);
        bool nflag = flag && (digit == lim);
        res += solve(pos + 1, nd, nflag, len);
    }
    dp[pos][d][flag] = res;
    return res;
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

    init();
    memset(dp, -1, sizeof(dp));
    while (std::cin >> n >> k)
    {
        x = 1;
        ans = 0;
        cnt = 1;
        while (x * 2 <= n)
        {
            x *= 2;
            cnt++;
        }

        for (int i = 1; i < cnt; i++)
        {
            if (i - 1 >= k)
            {
                ans += c[i - 1][k];
            }
        }

        if (cnt - 1 < k)
        {
            std::cout << ans << "\n";
            continue;
        }

        a = cnt - 1 - k;
        b = n - (1 << (cnt - 1));

        // Sửa điều kiện ở đây: bỏ điều kiện k > 0
        if (b >= 0)
        {
            int tmp = b;
            s.clear();
            while (tmp > 0)
            {
                if (tmp % 2 == 0)
                {
                    s += "0";
                }
                else
                {
                    s += "1";
                }
                tmp /= 2;
            }
            std::reverse(s.begin(), s.end());

            while (s.size() < cnt - 1)
            {
                s = '0' + s;
            }

            memset(dp, -1, sizeof(dp));
            ans += solve(0, 0, true, s.size());
        }

        std::cout << ans << "\n";
    }

    return 0;
}