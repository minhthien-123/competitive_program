#include <bits/stdc++.h>
#define task "sudoku"
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 500;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int mxx = 1e6 + 5;
const int inv = (mod + 1) / 2;

int m, n;
int a[maxn + 7][maxn + 7];
bool vis[maxn + 7][maxn + 7];
int a1[maxn + 7], a2[maxn + 7];

bool dfs(int u, std::vector<bool> &used, std::vector<int> adj[])
{
    for (int v : adj[u])
    {
        if (used[v])
            continue;
        used[v] = true;
        if (a1[v] == 0 || dfs(a1[v], used, adj))
        {
            a1[v] = u;
            a2[u] = v;
            return true;
        }
    }
    return false;
}

int main()
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
            vis[j][a[i][j]] = true;
        }
    }

    for (int k = m + 1; k <= n; k++)
    {
        std::vector<int> adj[maxn + 7];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!vis[i][j])
                    adj[i].pb(j);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            a1[i] = 0;
            a2[i] = 0;
        }

        for (int u = 1; u <= n; u++)
        {
            std::vector<bool> used(n + 1, false);
            if (!dfs(u, used, adj))
                return 0;
        }

        for (int i = 1; i <= n; i++)
        {
            int val = a2[i];
            std::cout << val << " ";
            vis[i][val] = true;
        }
        std::cout << '\n';
    }

    return 0;
}
