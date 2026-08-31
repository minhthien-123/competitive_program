#include <bits/stdc++.h>
#define task "tvcc"
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

int n, q;
int tin[maxn + 7], tout[maxn + 7], tour[maxn + 7], timer;
std::vector<int> adj[maxn + 7];
int bit[maxn + 7];

void dfs(int u, int p)
{
    tour[++timer] = u;
    tin[u] = timer;
    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
    tout[u] = timer;
}

void update(int id, int val)
{
    for (; id <= timer; id += id & -id)
    {
        bit[id] += val;
    }
}

void upd(int l, int r, int val)
{
    update(l, val);
    update(r + 1, -val);
}

int get(int id)
{
    int sum = 0;
    for (; id >= 1; id -= id & -id)
    {
        sum += bit[id];
    }
    return sum;
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
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, -1);

    while(q--)
    {
        int i, x;
        std::cin >> i >> x;
        upd(tin[i], tout[i], x);
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << get(tin[i]) << " ";
    }

    return 0;
}
