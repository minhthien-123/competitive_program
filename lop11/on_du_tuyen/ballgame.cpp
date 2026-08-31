#include <bits/stdc++.h>
#define task "ballgame"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;

int n, m;
ii v1[maxn + 7], v2[maxn + 7];
bool g[101][101];
int d[101][101];
int f[101][101], cnt[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int minX = 100, maxX = 0, minY = 100, maxY = 0;

int dist(ii a, ii b)
{
    return std::abs(a.fi - b.fi) + std::abs(a.se - b.se);
}

void bfs(int sx, int sy)
{
    std::queue<ii> q;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            d[i][j] = inf;
        }
    }

    d[sx][sy] = 0;
    q.push({sx, sy});

    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        int x = tmp.fi, y = tmp.se;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx > 100 || ny < 0 || ny > 100)
            {
                continue;
            }
            if (g[nx][ny])
            {
                continue;
            }
            if (d[nx][ny] > d[x][y] + 1)
            {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (d[i][j] < inf)
            {
                f[i][j] += d[i][j];
                cnt[i][j]++;
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> v1[i].fi >> v1[i].se;
    }

    std::cin >> m;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> v2[i].fi >> v2[i].se;
        minX = std::min(minX, v2[i].fi);
        maxX = std::max(maxX, v2[i].fi);
        minY = std::min(minY, v2[i].se);
        maxY = std::max(maxY, v2[i].se);
    }

    if (n == 0)
    {
        std::vector<int> x, y;
        for (int i = 1; i <= m; i++)
        {
            x.pb(v2[i].fi);
            y.pb(v2[i].se);
        }
        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());
        int mx = x[m / 2], my = y[m / 2];
        int res = 0;
        for (int i = 1; i <= m; i++)
        {
            res += dist(v2[i], {mx, my});
        }
        std::cout << res << "\n";
        return 0;
    }

    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++)
    {
        g[v1[i].fi][v1[i].se] = true;
    }

    for (int i = 1; i <= m; i++)
    {
        bfs(v2[i].fi, v2[i].se);
    }

    int ans = inf;
    for (int x = std::max(0LL, minX); x <= std::min(100LL, maxX); x++)
    {
        for (int y = std::max(0LL, minY); y <= std::min(100LL, maxY); y++)
        {
            if (!g[x][y] && cnt[x][y] == m)
            {
                ans = std::min(ans, f[x][y]);
            }
        }
    }

    if (ans == inf)
    {
        std::cout << -1 << "\n";
    }
    else
    {
        std::cout << ans << "\n";
    }

    return 0;
}
