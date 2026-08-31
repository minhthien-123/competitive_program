#include <bits/stdc++.h>
#define task "pour"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second

const int maxn = 20;
const int maxm = 50000;

int v, n, m, ans;
int a[maxn + 7];
int f[maxn + 7][maxm + 7];
std::queue<ii> q;

void pour(int x, int y, int val)
{
    for (int i = 0; i <= n; i++)
    {
        if (a[i] > x + y)
        {
            break;
        }

        int tmp = std::min(x + y - a[i], v - x - y);
        if (f[i][tmp] == -1)
        {
            f[i][tmp] = val + 1;
            q.push(ii(i, tmp));
        }
    }
}

void bfs()
{
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    q.push(ii(0, 0));

    while (!q.empty())
    {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        int z = v - a[x] - y;

        if (a[x] == m || y == m || z == m)
        {
            ans = f[x][y];
            return;
        }

        pour(a[x], y, f[x][y]);
        pour(a[x], z, f[x][y]);
        pour(y, a[x], f[x][y]);
        pour(y, z, f[x][y]);
        pour(z, a[x], f[x][y]);
        pour(z, y, f[x][y]);
    }
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


    std::cin >> v >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    a[++n] = v;

    ans = -1;
    bfs();
    std::cout << ans << "\n";
    return 0;
}
