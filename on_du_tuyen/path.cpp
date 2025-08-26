#include <bits/stdc++.h>
#define task "path"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
char a[maxn + 7][maxn + 7];
int d[maxn + 7][maxn + 7];
std::deque<ii> dq;

int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

void bfs()
{
    for (int i = 2; i < m; i++)
    {
        if (a[i][1] == '.')
        {
            d[i][1] = 1;
        }
        else
        {
            d[i][1] = 0;
        }
        if (a[i][1] == '#')
        {
            dq.push_front({i, 1});
        }
        else
        {
            dq.push_back({i, 1});
        }
    }

    while (!dq.empty())
    {
        int x = dq.front().fi;
        int y = dq.front().se;
        dq.pop_front();
        for (int i = 0; i <= 7; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 2 || nx >= m || ny < 1 || ny > n)
            {
                continue;
            }
            int tmp;
            if (a[nx][ny] == '.')
            {
                tmp = 1;
            }
            else
            {
                tmp = 0;
            }
            if (d[nx][ny] > d[x][y] + tmp)
            {
                d[nx][ny] = d[x][y] + tmp;
                if (tmp == 0)
                {
                    dq.push_front({nx, ny});
                }
                else
                {
                    dq.push_back({nx, ny});
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
            std::cin >> a[i][j];
            d[i][j] = inf;
        }
    }

    bfs();

    int ans = inf;
    for (int i = 2; i < m; i++)
    {
        ans = std::min(ans, d[i][n]);
    }

    std::cout << ans;

    return 0;
}
