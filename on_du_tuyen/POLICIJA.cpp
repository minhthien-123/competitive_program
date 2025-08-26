#include <bits/stdc++.h>
#define task "POLICIJA"
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

int n, m, q;
std::vector<int> adj[maxn + 7];

void tarjan(int u, int p)
{
    
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

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    std::cin >> q;

    while (q--)
    {
        int type, a, b, g1, g2, c;
        std::cin >> type >> a >> b;
        if (type == 1)
        {
            std::cin >> g1 >> g2;
        }
        else
        {
            std::cin >> c;
        }
    }

    return 0;
}
