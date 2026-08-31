#include <bits/stdc++.h>
#define task "d"
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

int n, m, Q;
char c[maxn + 7][maxn + 7];
int a[maxn + 7][maxn + 7], f[maxn + 7][maxn + 7];
int st[4 * maxn + 7][maxn + 7];
int ans[1000005];
std::bitset<maxn + 7> dp[maxn + 7][maxn + 7];

struct query
{
    int r1, r2, c1, c2, id;
};

void dnc(int l, int r, const std::vector<query> &v)
{
    if (l == r)
    {
        for (auto i : v)
        {
            int cnt = a[l][i.c2] - a[l][i.c1 - 1];
            ans[i.id] = (cnt == i.c2 - i.c1 + 1);
        }
        return;
    }

    int mid = (l + r) / 2;
    std::vector<query> p1, p2;

    for (int i = mid; i >= l; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            dp[i][j].reset();
            if (c[i][j] == '.')
            {
                dp[i][j] = dp[i][j + 1];
                if (i != mid)
                {
                    dp[i][j] |= dp[i + 1][j];
                }
                else
                {
                    dp[i][j][j] = 1;
                }
            }
        }
    }

    for (int i = mid + 1; i <= r; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j].reset();
            if (c[i][j] == '.')
            {
                dp[i][j] = dp[i][j - 1];
                if (i != mid + 1)
                {
                    dp[i][j] |= dp[i - 1][j];
                }
                else
                {
                    dp[i][j][j] = 1;
                }
            }
        }
    }

    for (auto &i : v)
    {
        if (i.r1 <= mid && i.r2 > mid)
        {
            ans[i.id] = ((dp[i.r1][i.c1] & dp[i.r2][i.c2]) != 0);
        }
        else if (i.r2 <= mid)
        {
            p1.pb(i);
        }
        else
        {
            p2.pb(i);
        }
    }

    dnc(l, mid, p1);
    dnc(mid + 1, r, p2);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m >> Q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> c[i][j];
            a[i][j] = a[i][j - 1] + (c[i][j] == '.');
        }
    }

    std::vector<query> q;
    for (int i = 1; i <= Q; i++)
    {
        query qq;
        std::cin >> qq.r1 >> qq.c1 >> qq.r2 >> qq.c2;
        qq.id = i;
        q.pb(qq);
    }

    dnc(1, n, q);

    for (int i = 1; i <= Q; i++)
    {
        if (ans[i])
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
    return 0;
}
