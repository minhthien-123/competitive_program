#include <bits/stdc++.h>
#define task "d7"
#define __Thien_dep_trai__ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define bit_set(x, pos) ((x) |= (1ULL << (pos)))
#define bit_clear(x, pos) ((x) &= ~(1ULL << (pos)))
#define all(x) x.begin(), x.end()

const int maxn = 1e3;
const int maxq = 1e6 + 7;
const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;

struct bypass
{
    int r1, c1, r2, c2;
    int id;
};
std::vector<bypass> query;

int n, m, q;
char c[maxn + 5][maxn + 5];
short a[maxn + 5][maxn + 5];
int ans[maxq];

std::bitset<1001> dp[maxn + 5][1005][2];

void dnc(int l, int r, std::vector<bypass> &v)
{
    if (v.empty())
    {
        return;
    }

    if (l == r)
    {
        for (auto &i : v)
        {
            int cnt = a[l][i.c2] - a[l][std::max(0, i.c1 - 1)];
            ans[i.id] = (cnt <= 0);
        }
        v.clear();
        v.shrink_to_fit();
        return;
    }

    int mid = (l + r) / 2;

    for (int j = m; j >= 1; j--)
    {
        dp[mid][j][0].reset();
        dp[mid][j][1].reset();
        if (c[mid][j] == '.')
        {
            dp[mid][j][0].set(j);
            dp[mid][j][1].set(j);
            if (j + 1 <= m)
            {
                dp[mid][j][0] |= dp[mid][j + 1][0];
                dp[mid][j][1] |= dp[mid][j + 1][1];
            }
        }
        else
        {
            dp[mid][j][1].set(j);
            if (j + 1 <= m)
            {
                dp[mid][j][1] |= dp[mid][j + 1][0];
            }
        }
    }

    for (int i = mid - 1; i >= l; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            dp[i][j][0].reset();
            dp[i][j][1].reset();
            if (c[i][j] == '.')
            {
                dp[i][j][0] = dp[i + 1][j][0];
                dp[i][j][1] = dp[i + 1][j][1];
                if (j + 1 <= m)
                {
                    dp[i][j][0] |= dp[i][j + 1][0];
                    dp[i][j][1] |= dp[i][j + 1][1];
                }
            }
            else
            {
                dp[i][j][1] = dp[i + 1][j][0];
                if (j + 1 <= m)
                {
                    dp[i][j][1] |= dp[i][j + 1][0];
                }
            }
        }
    }

    for (int j = 1; j <= m; j++)
    {
        dp[mid + 1][j][0].reset();
        dp[mid + 1][j][1].reset();
        if (c[mid + 1][j] == '.')
        {
            dp[mid + 1][j][0].set(j);
            dp[mid + 1][j][1].set(j);
            if (j - 1 >= 1)
            {
                dp[mid + 1][j][0] |= dp[mid + 1][j - 1][0];
                dp[mid + 1][j][1] |= dp[mid + 1][j - 1][1];
            }
        }
        else
        {
            dp[mid + 1][j][1].set(j);
            if (j - 1 >= 1)
            {
                dp[mid + 1][j][1] |= dp[mid + 1][j - 1][0];
            }
        }
    }

    for (int i = mid + 2; i <= r; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j][0].reset();
            dp[i][j][1].reset();
            if (c[i][j] == '.')
            {
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = dp[i - 1][j][1];
                if (j - 1 >= 1)
                {
                    dp[i][j][0] |= dp[i][j - 1][0];
                    dp[i][j][1] |= dp[i][j - 1][1];
                }
            }
            else
            {
                dp[i][j][1] = dp[i - 1][j][0];
                if (j - 1 >= 1)
                {
                    dp[i][j][1] |= dp[i][j - 1][0];
                }
            }
        }
    }

    std::vector<bypass> p1, p2;
    for (auto &i : v)
    {
        if (i.r1 <= mid && i.r2 > mid)
        {
            bool ok = (dp[i.r1][i.c1][0] & dp[i.r2][i.c2][0]).any();
            ans[i.id] = ok;
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

    v.clear();
    v.shrink_to_fit();

    dnc(l, mid, p1);
    p1.clear();
    p1.shrink_to_fit();

    dnc(mid + 1, r, p2);
    p2.clear();
    p2.shrink_to_fit();
}

void solve()
{
    std::cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> c[i][j];
            a[i][j] = a[i][j - 1] + (c[i][j] == '#');
        }
    }
    // std::cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;

        if (r1 > r2 || c1 > c2)
        {
            ans[i] = 0;
        }
        else
        {
            bypass qq = {r1, c1, r2, c2, i};
            query.pb(qq);
        }
    }

    dnc(1, n, query);

    for (int i = 1; i <= q; i++)
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
}

__Thien_dep_trai__
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    int tt = 1;
    while (tt--)
    {
        solve();
    }

    return 0;
}
