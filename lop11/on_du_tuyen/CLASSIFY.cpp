#include <bits/stdc++.h>
#define task "CLASSIFY"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e2;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
std::string a[maxn + 7], b[maxn + 7];

int solve(char c)
{
    if (c == 'A')
    {
        return (1LL << 0);
    }
    if (c == 'C')
    {
        return (1LL << 1);
    }
    if (c == 'G')
    {
        return (1LL << 2);
    }
    return (1LL << 3);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
    }

    int res = 0;
    for (int j = 0; j < m; j++)
    {
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++)
        {
            x |= solve(a[i][j]);
            y |= solve(b[i][j]);
        }
        if ((x & y) == 0)
        {
            res++;
        }
    }
    std::cout << res << "\n";

    return 0;
}
