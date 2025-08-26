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

int n, m, K, d[maxn][maxn];
char b[maxn][maxn], a[maxn][maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans = 0;
std::vector<ii> D[30];
bool check(int u, int v)
{
    if (u < 1 || u > n || v < 1 || v > m)
        return false;
    return true;
}

void bfs(int s, int t)
{
    std::queue<ii> q;
    memset(d, 0x3f, sizeof d);
    d[s][t] = 0;
    q.push({s, t});
    while (!q.empty())
    {
        int u = q.front().fi;
        int v = q.front().se;
        if (d[u][v] == 3)
        {
            break;
        }
        q.pop();
        for (int i = u + 1; i <= n + 1; i++)
        {
            if (d[i][v] < d[u][v])
            {
                break;
            }
            if (a[i][v] == a[s][t])
            {
                ans++;
                d[i][v] = 0;
                break;
            }
            if (a[i][v] != '.')
            {
                break;
            }
            if (d[i][v] > d[u][v] + 1)
            {
                d[i][v] = d[u][v] + 1;
                q.push(ii(i, v));
            }
        }
        for (int i = u - 1; i >= 0; i--)
        {
            if (d[i][v] < d[u][v])
            {
                break;
            }
            if (a[i][v] == a[s][t])
            {
                ans++;
                d[i][v] = 0;
                break;
            }
            if (a[i][v] != '.')
            {
                break;
            }
            if (d[i][v] > d[u][v] + 1)
            {
                d[i][v] = d[u][v] + 1;
                q.push(ii(i, v));
            }
        }
        for (int i = v + 1; i <= m + 1; i++)
        {
            if (d[u][i] < d[u][v])
            {
                break;
            }
            if (a[u][i] == a[s][t])
            {
                ans++;
                d[u][i] = 0;
                break;
            }
            if (a[u][i] != '.')
            {
                break;
            }
            if (d[u][i] > d[u][v] + 1)
            {
                d[u][i] = d[u][v] + 1;
                q.push(ii(u, i));
            }
        }
        for (int i = v - 1; i >= 0; i--)
        {
            if (d[u][i] < d[u][v])
            {
                break;
            }
            if (a[u][i] == a[s][t])
            {
                ans++;
                d[u][i] = 0;
                break;
            }
            if (a[u][i] != '.')
            {
                break;
            }
            if (d[u][i] > d[u][v] + 1)
            {
                d[u][i] = d[u][v] + 1;
                q.push(ii(u, i));
            }
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            a[i][j] = '.';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != '.')
            {
                bfs(i, j);
            }
        }
    }

    std::cout << ans / 2;

    return 0;
}