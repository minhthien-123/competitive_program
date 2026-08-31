#include <bits/stdc++.h>
#define task "water"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;

struct water
{
    int h, x, y;
    friend bool operator<(water x, water y)
    {
        return x.h > y.h;
    }
};

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
    std::vector<std::vector<int>> a(m + 7, std::vector<int>(n + 7));
    std::vector<std::vector<bool>> vis(m + 7, std::vector<bool>(n + 7, 0));
    std::priority_queue<water> pq;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        pq.push({a[i][1], i, 1});
        pq.push({a[i][n], i, n});
        vis[i][1] = vis[i][n] = true;
    }
    for (int j = 2; j < n; j++)
    {
        pq.push({a[1][j], 1, j});
        pq.push({a[m][j], m, j});
        vis[1][j] = vis[m][j] = true;
    }

    int ans = 0;

    while (!pq.empty())
    {
        water t = pq.top();
        int x = t.x;
        int y = t.y;
        int h = t.h;
        pq.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 1 || nx > m || ny < 1 || ny > n || vis[nx][ny])
            {
                continue;
            }
            vis[nx][ny] = true;
            if (a[nx][ny] < h)
            {
                ans += h - a[nx][ny];
                pq.push({h, nx, ny});
            }
            else
            {
                pq.push({a[nx][ny], nx, ny});
            }
        }
    }

    std::cout << ans;

    return 0;
}
