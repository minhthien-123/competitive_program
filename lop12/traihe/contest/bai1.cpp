#include <bits/stdc++.h>
#define int long long

const int maxn = 2e3;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
char a[maxn + 7][maxn + 7];
bool vis[maxn + 7][maxn + 7][4];
bool flag[maxn + 7][maxn + 7];

int get(char c)
{
    if (c == 'R')
    {
        return 0;
    }
    if (c == 'D')
    {
        return 1;
    }
    if (c == 'L')
    {
        return 2;
    }
    if (c == 'U')
    {
        return 3;
    }
    return -1;
}

bool check(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int idx(int i, int j, int d)
{
    return 4 * (i * maxn + j) + d;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> a[i][j];
        }
    }

    std::queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int d = get(a[i][j]);
            if (d != -1)
            {
                vis[i][j][d] = true;
                q.push(idx(i, j, d));
            }
        }
    }

    while (q.size())
    {
        int val = q.front();
        q.pop();

        int d = val % 4;
        int x = (val / 4) / maxn;
        int y = (val / 4) % maxn;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (!check(nx, ny))
        {
            continue;
        }

        if (a[nx][ny] == '#')
        {
            flag[nx][ny] = true;
        }
        else if (a[nx][ny] == '.')
        {
            if (!vis[nx][ny][d])
            {
                vis[nx][ny][d] = true;
                q.push(idx(nx, ny, d));
            }
        }
        else
        {
            int nd = get(a[nx][ny]);
            if (nd != -1 && !vis[nx][ny][nd])
            {
                vis[nx][ny][nd] = true;
                q.push(idx(nx, ny, nd));
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (flag[i][j])
            {
                ans++;
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}
