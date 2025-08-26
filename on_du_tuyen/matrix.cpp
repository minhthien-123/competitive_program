#include <bits/stdc++.h>
#define task "matrix"
#define _Thiendeptrai_ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1500;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;

int n;
int a[maxn][maxn];
ll d[maxn][maxn];
ll ans = 0;

void init()
{
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll res = -inf;
            if (i == 1 && j == 1)
            {
                res = 0;
            }
            res = std::max({res, d[i - 1][j], d[i][j - 1]});
            if (res == -inf)
            {
                res = 0;
            }
            d[i][j] = res + a[i][j];
            ans += d[i][j];
        }
    }
}

void solve(int sx, int ty)
{
    for (int i = sx; i <= n; i++)
    {
        for (int j = ty; j <= n; j++)
        {
            ll pre = d[i][j];
            ll res = -inf;
            if (i == 1 && j == 1)
            {
                res = 0;
            }
            res = std::max({res, d[i - 1][j], d[i][j - 1]});
            if (res == -inf)
            {
                res = 0;
            }
            ll tmp = res + a[i][j];
            d[i][j] = tmp;
            ans += (tmp - pre);
        }
    }
}

_Thiendeptrai_
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
            d[i][j] = 0;
        }
    }

    init();
    std::cout << ans << '\n';

    while (n--)
    {
        char c;
        int s, t;
        std::cin >> c >> s >> t;
        if (c == 'U')
        {
            a[s][t] += 1;
        }
        else
        {
            a[s][t] -= 1;
        }
        solve(s, t);
        std::cout << ans << '\n';
    }

    return 0;
}