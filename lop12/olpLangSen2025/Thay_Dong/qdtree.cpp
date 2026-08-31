#include <bits/stdc++.h>
#define task "subset"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, q, timer;
int a[maxn + 7];
int tin[maxn + 7], tout[maxn + 7], s[maxn + 7];
std::vector<int> adj[maxn + 7], vec[maxn + 7];

void dfs(int u, int p)
{
    s[u] = p;
    tin[u] = ++timer;
    vec[p].pb(tin[u]);

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, p + 1);
        }
    }

    tout[u] = timer;
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

    std::cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int x;
        std::cin >> x;
        adj[x].pb(i);
    }

    dfs(1, 0);

    while (q--)
    {
        int v, d;
        std::cin >> v >> d;
        int tmp = s[v] + d;
        if (tmp > n)
        {
            std::cout << "0\n";
        }
        else
        {
            std::cout << std::upper_bound(vec[tmp].begin(), vec[tmp].end(), tout[v]) - std::lower_bound(vec[tmp].begin(), vec[tmp].end(), tin[v]) << "\n";
        }
    }

    return 0;
}
