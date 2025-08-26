#include <bits/stdc++.h>
#define task "trapa"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m, k, l;
std::vector<int> adj[maxn + 7];
bool a[maxn + 7], b[maxn + 7];
int da, db;
int cnta[maxn + 7], cntb[maxn + 7];
int num[maxn + 7], low[maxn + 7], timer;
int ans = 0;

void tarjan(int u, int p)
{
    num[u] = low[u] = ++timer;
    cnta[u] = a[u];
    cntb[u] = b[u];

    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }

        if (!num[v])
        {
            tarjan(v, u);

            low[u] = std::min(low[u], low[v]);

            cnta[u] += cnta[v];
            cntb[u] += cntb[v];

            if (low[v] > num[u])
            {
                if (cnta[v] == 0 || cntb[v] == 0 || da == cnta[v] || db == cntb[v])
                {
                    ans++;
                }
            }
        }
        else
        {
            low[u] = std::min(low[u], num[v]);
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

    std::cin >> n >> m >> k >> l;
    while (k--)
    {
        int x;
        std::cin >> x;
        a[x] = true;
        da++;
    }
    while (l--)
    {
        int x;
        std::cin >> x;
        b[x] = true;
        db++;
    }

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
        {
            tarjan(u, u);
        }
    }

    std::cout << ans;

    return 0;
}
