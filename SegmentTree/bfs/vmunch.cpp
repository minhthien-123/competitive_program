#include <bits/stdc++.h>
#define task "vmunch"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;
const int inf  = 1e18 + 7;

int m, n;
int a[maxn][maxn];
ii start, end;
int dx[] = {-1,  0, 1, 0};
int dy[] = { 0, -1, 0 ,1};
int d[maxn][maxn];
std::priority_queue<std::pair<int, ii>, std::vector<std::pair<int, ii>>, std::greater<std::pair<int, ii>>> pq;

bool check(int x, int y)
{
    if (x < 1 || y < 1 || x > m || y > n) return false;
    return true;
}

void bfs(ii s)
{
    while (pq.size())
    {
        int dist = pq.top().fi;
        ii t = pq.top().se;
        pq.pop();
        int x = t.fi, y = t.se;

        if (a[x][y] != 0)
        {
            continue;
        }

        if (dist > d[x][y])
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny))
            {
                if (a[nx][ny] != 1 && d[nx][ny] > d[x][y] + 1)
                {
                    d[nx][ny] = d[x][y] + 1;
                    pq.push({d[nx][ny], {nx, ny}});
                }
            }
        }
    }
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

    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            std::cin >> c;
            if (c == 'B')
            {
                start = std::make_pair(i, j);
                a[i][j] = 0;
            }
            else if (c == 'C')
            {
                end = std::make_pair(i, j);
                a[i][j] = 0;
            }
            else if (c == '*')
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = inf;
        }
    }

    /*for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << end.fi << " " << end.se << "\n";*/

    pq.push({0, end});
    d[end.fi][end.se] = 0;

    bfs(end);

    /*for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << d[i][j] << " ";
        }
        std::cout << "\n";
    }*/

    std::cout << d[start.fi][start.se];

    return 0;
}
