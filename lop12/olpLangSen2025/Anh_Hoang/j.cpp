#include <bits/stdc++.h>
#define task "d"
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, Q;
int ans[maxn + 7];

struct query
{
    int r1, r2, c1, c2, id;
} q[maxn + 7];

std::vector<int> v;
std::vector<std::vector<int>> a, suf, f;

void dnc(int l, int r, const std::vector<int> &v)
{
    if (l == r)
    {
        for (int i : v)
        {
            ans[i] = suf[l][q[i].c2] - suf[l][q[i].c1 - 1];
        }
        return;
    }
    int mid = (l + r) / 2;

    std::vector<int> p1, p2, p3;
    for (int i : v)
    {
        if (q[i].r2 <= mid)
        {
            p1.pb(i);
        }
        else if (q[i].r1 > mid)
        {
            p2.pb(i);
        }
        else
        {
            p3.pb(i);
        }
    }

    for (int k = 1; k <= m; k++)
    {
        for (int i = l; i <= mid; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                f[i][j] = inf;
            }
        }
        f[mid][k] = a[mid][k];
        for (int i = mid; i >= l; i--)
        {
            for (int j = m; j >= 1; j--)
            {
                if (j + 1 <= m)
                {
                    f[i][j] = std::min(f[i][j], a[i][j] + f[i][j + 1]);
                }
                if (i + 1 <= mid)
                {
                    f[i][j] = std::min(f[i][j], a[i][j] + f[i + 1][j]);
                }
            }
        }
        for (int i = mid + 1; i <= r; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                f[i][j] = inf;
            }
        }
        f[mid + 1][k] = a[mid + 1][k];
        for (int i = mid + 1; i <= r; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j - 1 >= 1)
                {
                    f[i][j] = std::min(f[i][j], a[i][j] + f[i][j - 1]);
                }
                if (i - 1 > mid)
                {
                    f[i][j] = std::min(f[i][j], a[i][j] + f[i - 1][j]);
                }
            }
        }
        for (int i : p3)
        {
            ans[i] = std::min(ans[i], f[q[i].r1][q[i].c1] + f[q[i].r2][q[i].c2]);
        }
    }

    dnc(l, mid, p1);
    dnc(mid + 1, r, p2);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m >> Q;
    std::vector<std::vector<int>> c(n + 1, std::vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> c[i][j];
        }
    }

    bool check = (m > n);
    if (check)
    {
        std::swap(m, n);
        a.assign(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = c[j][i];
            }
        }
    }
    else
    {
        a.assign(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = c[i][j];
            }
        }
    }

    suf.assign(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            suf[i][j] = suf[i][j - 1] + a[i][j];
        }
    }

    v.reserve(Q);
    for (int i = 1; i <= Q; i++)
    {
        std::cin >> q[i].r1 >> q[i].c1 >> q[i].r2 >> q[i].c2;
        if (check)
        {
            std::swap(q[i].r1, q[i].c1);
            std::swap(q[i].r2, q[i].c2);
        }
        q[i].id = i;
        v.pb(i);
        ans[i] = inf;
    }

    f.assign(n + 2, std::vector<int>(m + 2, inf));
    dnc(1, n, v);

    for (int i = 1; i <= Q; i++)
    {
        std::cout << ans[i] << '\n';
    }

    return 0;
}
