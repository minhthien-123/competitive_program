#include <bits/stdc++.h>
#define task "numtab"
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

int m, n, q;
int b[maxn * maxn + 7];
int a[maxn + 7][maxn + 7];
int f[10 + 7];
int pre[maxn + 7][maxn + 7][3];
int mn[maxn + 7], mx[maxn + 7];
int ans[maxn + 7][maxn + 7];
int H[maxn + 7];
int ansq[maxn + 7][maxn + 7];

bool check(int x)
{
    return (x & (x >> 1)) != 0;
}

int f_(int x)
{
    int cnt = 0;
    for (int i = 1; i <= x; i++)
    {
        if (check(i))
        {
            cnt++;
        }
    }
    return cnt;
}

void init1()
{
    for (int i = 1; i <= 10; i++)
    {
        f[i] = f_(i);
    }

    for (int i = 1; i <= m * n; i++)
    {
        int x = (i - 1) / n + 1;
        int y = (i - 1) % n + 1;
        int val = (f[b[i]] % 3);
        a[x][y] = val;
    }
}

void sub1()
{
    init1();
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mn[j] = inf;
            mx[j] = -inf;
        }
        for (int j = i; j <= m; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (a[j][k] < mn[k])
                {
                    mn[k] = a[j][k];
                }
                if (a[j][k] > mx[k])
                {
                    mx[k] = a[j][k];
                }
            }

            std::deque<ii> dqmax, dqmin;
            int l = 1;
            int res = 0;
            for (int r = 1; r <= n; ++r)
            {
                int Mx = mx[r];
                int Mn = mn[r];
                while (dqmax.size() && dqmax.back().fi <= Mx)
                {
                    dqmax.pop_back();
                }
                dqmax.push_back({Mx, r});
                while (dqmin.size() && dqmin.back().fi >= Mn)
                {
                    dqmin.pop_back();
                }
                dqmin.push_back({Mn, r});

                while (dqmax.size() && dqmin.size() && (dqmax.front().fi - dqmin.front().fi > 1))
                {
                    if (dqmax.size() && dqmax.front().second == l)
                    {
                        dqmax.pop_front();
                    }
                    if (dqmin.size() && dqmin.front().second == l)
                    {
                        dqmin.pop_front();
                    }
                    l++;
                }
                res = std::max(res, r - l + 1);
            }
            ans[i][j] = res * (j - i + 1);
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        H[i] = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = i; j <= m; ++j)
        {
            int h = j - i + 1;
            H[h] = std::max(H[h], ans[i][j]);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int cur = 0;
        for (int j = i; j <= m; j++)
        {
            cur = std::max(cur, H[j]);
            ansq[i][j] = cur;
        }
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

    std::cin >> m >> n;
    for (int i = 1; i <= m * n; i++)
    {
        std::cin >> b[i];
    }
    std::cin >> q;

    sub1();

    /*for (int i = 1; i <= 10; i++)
    {
        std::cout << f[i] << " ";
    }
    std::cout << "\n";

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }*/

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << ansq[x][y] << "\n";
    }

    return 0;
}
