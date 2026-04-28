#include <bits/stdc++.h>
#define task ""
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
const int bl   = 320;

int n, q;
std::vector<int> adj[maxn + 7], heavy[maxn + 7];
int lz[maxn + 7], val[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int u = 1; u <= n; u++)
    {
        for (int v : adj[u])
        {
            if (adj[u].size() > bl || adj[v].size() > bl)
            {
                heavy[u].pb(v);
            }
        }
    }

    while (q--)
    {
        int type, u, d;
        std::cin >> type >> u;
        if (type == 1)
        {
            std::cin >> d;
            if (adj[u].size() > bl)
            {
                lz[u] += d;
            }
            else
            {
                for (int v : adj[u])
                {
                    val[v] += d;
                }
            }
        }
        else
        {
            int res = val[u];
            for (int v : heavy[u])
            {
                res += lz[v];
            }
            std::cout << res << "\n";
        }
    }

    return 0;
}
