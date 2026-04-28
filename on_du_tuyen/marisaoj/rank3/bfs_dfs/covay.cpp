#include <bits/stdc++.h>
#define task "covay"
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 507;

char a[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int m, n;
bool vis[maxn][maxn];

bool check(int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n && a[x][y] != '#');
}

int bfs(int u, int v)
{
    bool flag = true;
    int cnt = 0;
    a[u][v] = '#';

    std::queue<ii> q;
    q.push({u, v});

    while (q.size())
    {
        ii t = q.front();
        q.pop();
        int x = t.fi, y = t.se;

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (check(nx, ny) && a[nx][ny] != '#')
            {
                if (a[nx][ny] == '.')
                {
                    flag = false;
                }
                else if (a[nx][ny] == 'W')
                {
                    cnt++;
                    a[nx][ny] = '#';
                    q.push({nx, ny});
                }
                else if (a[nx][ny] == 'B')
                {
                    a[nx][ny] = '#';
                }
            }
        }
    }

    //cout << cnt << "\n";

    if (flag)
        return cnt + 1;
    else
        return 0;
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
    a[0][0] = a[0][n + 1] = a[m + 1][0] = a[m + 1][n + 1] = 'B';
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'W')
            {
                //std::cout << i << " " << j << "\n";
                ans += bfs(i, j);
            }
        }
    }

    std::cout << ans;

    return 0;
}
