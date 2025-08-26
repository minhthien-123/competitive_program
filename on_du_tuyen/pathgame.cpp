#include <bits/stdc++.h>
#define task "pathgame"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3;
const int inf = 1e18;

int n, m, q;
char a[maxn + 7][maxn + 7];
int d[maxn + 7][maxn + 7];
std::deque<ii> dq;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n);
}

void bfs()
{
    while (!dq.empty())
    {
        int x = dq.front().fi;
        int y = dq.front().se;
        dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!valid(nx, ny))
            {
                continue;
            }

            int cost = 0;
            if (a[nx][ny] != a[x][y])
            {
                cost = 1;
            }

            if (d[nx][ny] > d[x][y] + cost)
            {
                d[nx][ny] = d[x][y] + cost;
                if (cost == 0)
                {
                    dq.push_front({nx, ny});
                }
                else
                {
                    dq.pb({nx, ny});
                }
            }
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    std::cin >> m >> n >> q;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] == '*')
            {
                d[i][j] = 0;
                dq.push_back({i, j});
            }
            else
            {
                d[i][j] = inf;
            }
        }
    }

    bfs();

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << d[x][y] << "\n";
    }
    return 0;
}
