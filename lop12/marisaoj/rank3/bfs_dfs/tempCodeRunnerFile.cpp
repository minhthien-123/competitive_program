#include <bits/stdc++.h>
#define task "LeHoi2"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf = 1e9 + 7;

int n, m, k, ans = LLONG_MAX;
int a[maxn], b[maxn], d1[maxn], d2[maxn], p[maxn];
std::vector<int> adj[maxn];

void bfs(int s, int d[])
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }
    d[s] = 0;
    std::queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int v : adj[t])
        {
            if (d[v] == inf)
            {
                d[v] = d[t] + 1;
                q.push(v);
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

    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        std::cin >> p[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        a[i] = u;
        b[i] = v;
    }

    /*for (int i = 1; i <= m; i++)
    {
        bfs(a[i], d1);
        bfs(b[i], d2);
        int tmp = 0;

        /*for (int j = 1; j <= k; j++)
        {
            std::cout << d1[p[j]] << " ";
        }
        std::cout << "\n";
        for (int j = 1; j <= k; j++)
        {
            std::cout << d2[p[j]] << " ";
        }
        std::cout << "\n\n";

        for (int j = 1; j <= k; j++)
        {
            tmp += std::min(d1[j], d2[j]);
        }
        ans = std::min(ans, tmp);
    }*/

    for (int i = 1; i <= m; i++)
    {
        bfs(a[i], d1);
        bfs(b[i], d2);
        int tmp = 0;

        for (int cnt = 1; cnt <= k; cnt++)
        {
            tmp += std::min(d1[p[cnt]], d2[p[cnt]]);
        }

        /*for (int cnt = 1; cnt <= k; cnt ++)
        {
            std::cout << d1[p[cnt]] << " ";
        }
        std::cout << "\n";
        for (int cnt = 1; cnt <= k; cnt++)
        {
            std::cout << d2[p[cnt]] << " ";
        }
        std::cout << "\n";
        std::cout << a[i] << " " << b[i] << "\n";
        std::cout << tmp << "\n\n";*/

        ans = std::min(ans, tmp);
    }

    std::cout << ans;

    return 0;
}
