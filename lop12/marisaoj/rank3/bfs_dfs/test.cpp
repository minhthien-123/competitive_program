#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[505][505];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
}

bool safe(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

int bfs(int x, int y)
{
    bool ok = true;
    int cnt = 0;
    a[x][y] = '#';

    queue<pair<int, int>> q;
    q.push({x, y});

    int x1, y1;
    while (q.size())
    {
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            x1 = x + dx[i];
            y1 = y + dy[i];

            if (safe(x1, y1) && a[x1][y1] != '#')
            {
                if (a[x1][y1] == '.')
                    ok = false;
                else if (a[x1][y1] == 'W')
                {
                    ++cnt;
                    a[x1][y1] = '#';
                    q.push({x1, y1});
                }
                else if (a[x1][y1] == 'B')
                    a[x1][y1] = '#';
            }
        }
    }

    cout << cnt << "\n";

    if (ok)
        return cnt + 1;
    else
        return 0;
}

void process()
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 'W' && a[i][j] != '#')
                res += bfs(i, j);
        }
    }

    cout << res;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    inp();
    process();

    return 0;
}