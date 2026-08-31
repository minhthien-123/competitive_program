#include <bits/stdc++.h>
#define task "colorec"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int tt = 200;

int n;
int a[405][405];
std::vector<ii> f[5][5];

void init()
{
    for (int x = 1; x <= 4; ++x)
    {
        for (int y = 1; y <= 4; ++y)
        {
            if (x != y)
            {
                std::vector<int> v;
                for (int c = 1; c <= 4; ++c)
                {
                    if (c != x && c != y)
                    {
                        v.pb(c);
                    }
                }
                f[x][y].pb({v[0], v[1]});
                f[x][y].pb({v[1], v[0]});
            }
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

    init();

    std::cin >> n;
    memset(a, 0, sizeof(a));

    for (int i = 0; i < n; ++i)
    {
        int x, y, c;
        std::cin >> x >> y >> c;
        a[x + tt][y + tt] = c;
    }

    int cnt = 0;

    for (int i = 0; i <= 400; ++i)
    {
        for (int j = i + 1; j <= 400; ++j)
        {
            int g[5][5] = {0};
            for (int k = 0; k <= 400; ++k)
            {
                int x = a[i][k];
                int y = a[j][k];
                if (x != 0 && y != 0 && x != y)
                {
                    for (auto p : f[x][y])
                    {
                        cnt += g[p.fi][p.se];
                    }
                }

                g[x][y]++;
            }
        }
    }

    std::cout << cnt << '\n';

    return 0;
}