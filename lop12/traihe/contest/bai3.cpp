#include <bits/stdc++.h>
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second

const int maxn = 2e3;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char c[] = {'R', 'D', 'L', 'U'};

int n, m;
char a[maxn + 7][maxn + 7];
bool vis[maxn + 7][maxn + 7];
char trace[maxn + 8][maxn + 7];
ii par[maxn + 7][maxn + 7];

bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

ii move(ii p, char c)
{
    int x = p.fi, y = p.se;
    if (!check(x, y))
    {
        return p;
    }

    int nx = x, ny = y;
    if (c == 'U')
    {
        nx--;
    }
    else if (c == 'D')
    {
        nx++;
    }
    else if (c == 'L')
    {
        ny--;
    }
    else if (c == 'R')
    {
        ny++;
    }

    if (!check(nx, ny))
    {
        return {nx, ny};
    }
    if (a[nx][ny] == '1')
    {
        return p;
    }
    return {nx, ny};
}

std::string bfs(int sx, int sy)
{
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            vis[i][j] = false;
        }
    }

    std::queue<ii> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    int ansx = -1, ansy = -1;

    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();

        if (!check(x, y))
        {
            ansx = x;
            ansy = y;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1)
            {
                if (!vis[nx][ny])
                {
                    if (nx == 0 || nx == n + 1 || ny == 0 || ny == m + 1 || a[nx][ny] == '0')
                    {
                        vis[nx][ny] = true;
                        trace[nx][ny] = c[i];
                        par[nx][ny] = {x, y};
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    std::string path = "";
    int curx = ansx, cury = ansy;
    while (curx != sx || cury != sy)
    {
        path += trace[curx][cury];
        auto [pr, pc] = par[curx][cury];
        curx = pr;
        cury = pc;
    }

    std::reverse(path.begin(), path.end());
    return path;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> a[i][j];
        }
    }

    std::queue<ii> qu;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '0')
            {
                qu.push({i, j});
            }
        }
    }

    std::string str = "";

    while (qu.size())
    {
        ii tmp = qu.front();
        qu.pop();
        std::string path = bfs(tmp.fi, tmp.se);
        str += path;

        int sz = qu.size();
        std::vector<ii> vec;

        while (sz--)
        {
            ii p = qu.front();
            qu.pop();

            for (char ch : path)
            {
                p = move(p, ch);
                if (!check(p.fi, p.se))
                {
                    break;
                }
            }

            if (check(p.fi, p.se))
            {
                vec.push_back(p);
            }
        }

        std::sort(vec.begin(), vec.end());
        vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

        for (auto p : vec)
        {
            qu.push(p);
        }
    }

    std::cout << str;
}
