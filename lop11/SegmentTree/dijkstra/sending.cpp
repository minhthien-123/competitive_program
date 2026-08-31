#include <bits/stdc++.h>
#define task "dijkstra"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 400;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
std::vector<int> adj[maxn + 7];
int d[maxn + 7][maxn + 7];

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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> m;
        while (m--)
        {
            int x;
            std::cin >> x;
            adj[i].pb(x);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = inf;
        }
    }

    std::queue<int> q;
    for (int s = 1; s <= n; s++)
    {
        d[s][s] = 0;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (d[s][v] == inf)
                {
                    d[s][v] = d[s][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int k;
    std::cin >> k;
    while (k--)
    {
        int s, t;
        std::cin >> s >> t;
        if (d[s][t] == inf)
        {
            std::cout << -1;
        }
        else
        {
            std::cout << d[s][t] - 1;
        }
        std::cout << "\n";
    }

    return 0;
}