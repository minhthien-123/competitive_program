#include <bits/stdc++.h>
#define task "pikachu"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 100;
const int inf = 1e9;

int m, n, K;
char a[maxn + 7][maxn + 7], f[maxn + 7][maxn + 7];
int d[maxn + 7][maxn + 7][4];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int x, int y)
{
    return x >= 0 && x <= m + 1 && y >= 0 && y <= n + 1;
}

bool bfs(int x, int y, int u, int v)
{
    for (int i = 0; i <= m + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                d[i][j][k] = inf;
            }
        }
    }
    std::deque<iii> dq;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (valid(nx, ny) && (a[nx][ny] == '.' || (nx == u && ny == v)))
        {
            d[nx][ny][k] = 0;
            dq.pb(iii(ii(nx, ny), k));
        }
    }
    while (!dq.empty())
    {
        int tmpx = dq.front().fi.fi;
        int tmpy = dq.front().fi.se;
        int tmpk = dq.front().se;
        dq.pop_front();
        int tmp = d[tmpx][tmpy][tmpk];
        if (tmp == K)
        {
            continue;
        }
        if (tmpx == u && tmpy == v)
        {
            return true;
        }
        for (int k = 0; k < 4; k++)
        {
            int nx = tmpx + dx[k];
            int ny = tmpy + dy[k];
            int nb = tmp + (k != tmpk);
            if (!valid(nx, ny) || nb == K)
            {
                continue;
            }
            if (!(a[nx][ny] == '.' || (nx == u && ny == v)))
            {
                continue;
            }
            if (d[nx][ny][k] > nb)
            {
                d[nx][ny][k] = nb;
                if (k == tmpk)
                {
                    dq.push_front(iii(ii(nx, ny), k));
                }
                else
                {
                    dq.push_back(iii(ii(nx, ny), k));
                }
            }
        }
    }
    return false;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    std::cin >> m >> n >> K;

    for (int i = 0; i <= m + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            a[i][j] = '.';
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    std::vector<ii> pos[26];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != '.')
            {
                pos[a[i][j] - 'A'].pb(ii(i, j));
            }
        }
    }

    int ans = 0;
    for (int c = 0; c < 26; c++)
    {
        std::vector<ii> v = pos[c];
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                if (bfs(v[i].fi, v[i].se, v[j].fi, v[j].se))
                {
                    ans++;
                }
            }
        }
    }

    std::cout << ans;

    return 0;
}
