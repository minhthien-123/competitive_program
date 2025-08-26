#include <bits/stdc++.h>
#define task "rbgame"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int h, w;
int d[maxn + 7][maxn + 7], a[maxn + 7][maxn + 7];

bool valid(int u, int v)
{
    return 1 <= u && u <= m && 1 <= v && v <= n;
}

void dijk()
{
    std::priority_queue<iii, std::vector<iii>, std::greater<iii>> pq;
    for (int i = 2; i <= n; i++)
    {
        d[1][i] = a[1][i];
        pq.push({d[1][i], {1, i}});
    }
    for (int i = 2; i < m; i++)
    {
        d[i][n] = a[i][n];
        pq.push({d[i][n], {i, n}});
    }

    while (pq.size())
    {
        auto t = pq.top();
        int w = t.fi;
        int x = t.se.fi;
        int y = t.se.se;
        pq.pop();

        if (w > d[x][y])
        {
            continue;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (valid(nx, ny))
            {
                if (d[nx][ny] > d[x][y] + a[nx][ny])
                {
                    d[nx][ny] = d[x][y] + a[nx][ny];
                    pq.push({d[nx][ny], {nx, ny}});
                }
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

    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            std::cin >> c;
            if (c == '.')
            {
                a[i][j] = inf;
            }
            else if (c == '#')
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = c - '0';
            }
            d[i][j] = inf;
        }
    }

    /*for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout << "\n";
    }
    std::cout << "\n";*/

    dijk();

    /*for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << d[i][j] << ' ';
        }
        std::cout << "\n";
    }*/

    int ans = inf;
    for (int i = 1; i < n; i++)
    {
        ans = std::min(ans, d[m][i]);
    }
    for (int j = 2; j < m; j++)
    {
        ans = std::min(ans, d[j][1]);
    }

    if (ans == inf)
    {
        ans = -1;
    }

    std::cout << ans;

    return 0;
}
