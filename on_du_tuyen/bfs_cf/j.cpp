#include <bits/stdc++.h>
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second

const int maxn = 1e3 + 7;
int n, m, k, a[maxn][maxn], d[maxn][maxn], cnt, ans, flag;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool vis[maxn][maxn];
ii t;
std::queue<ii> q;

bool check(int x, int y)
{
    if (!a[x][y] || x < 1 || y < 1 || x > n || y > m)
        return false;
    return true;
}

void bfs(int x, int y)
{
    memset(d, 1, sizeof d);

    while (!q.empty())
    {
        ii l = q.front();
        q.pop();
        if (!d[l.fi][l.se])
            continue;
        cnt++;
        a[l.fi][l.se]++;
        d[l.fi][l.se]++;
        if ((cnt + k) == ans)
            for (int i = 1; i <= n; i++)
                for (int j = 1; i <= m; j++)
                    if (d[i][j] && a[i][j])
                    {
                        flag = true;
                        std::cout << i << " " << j << "\n";
                    }
        for (int i = 0; i < 4; i++)
        {
            int nx = l.fi + dx[i], ny = l.se + dy[i];
            if (check(nx, ny))
                q.push({nx, ny});
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
            if (a[i][j])
                ans++;
            if (a[i][j] && !t.fi && !t.se)
                t = {i, j};
        }

    q.push(t);
    bfs(t.fi, t.se);

    return 0;
}
