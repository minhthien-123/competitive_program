#include <bits/stdc++.h>
#define task "fish"
#define ll long long
#define ld long double
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e6 + 7;
const double eps = 1e-6;

int n;
int par[maxn][20];
ld a[maxn];
int k[maxn];
std::vector<std::pair<int, std::pair<ld, int>>> adj[maxn];

void dfs(int u)
{
    for (std::pair<int, std::pair<ld, int>> v : adj[u])
        if (par[u][0] != v.fi)
        {
            par[v.fi][0] = u;
            a[v.fi] = (a[u] * v.se.fi / 100.0);
            if (v.se.se == 1)
            {
                a[v.fi] = a[v.fi] * a[v.fi];
            }
            dfs(v.fi);
        }
}
bool check(ld mid)
{
    a[1] = mid;
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (k[i] != -1 && a[i] < k[i])
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen(task ".inp", "r", stdin);
    std::freopen(task ".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w, type;
        std::cin >> u >> v >> w >> type;
        adj[u].pb({v, {w, type}});
        adj[v].pb({u, {w, type}});
    }

    for (int i = 1; i <= n; i++)
    {
        std::cin >> k[i];
    }

    ld l = 1, r = 2e9, ans;
    int c = 100;

    while (r - l > eps)
    {
        ld mid = (l + r) / 2.0;
        if (check(mid))
        {
            ans = mid;
            r = mid - eps;
        }
        else
        {
            l = mid + eps;
        }
    }
    std::cout << std::fixed << std::setprecision(4) << ans;

    return 0;
}