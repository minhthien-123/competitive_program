#include <bits/stdc++.h>
#define task "slow"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 200007;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
std::vector<int> adj[maxn];
bool vis[maxn];
int par[maxn];
int tin[maxn], tout[maxn];
int timer = 0;
int bit[maxn];

void update(int idx, int val)
{
    while (idx <= timer)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int get(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void dfs(int u, int p)
{
    vis[u] = true;
    par[u] = p;
    tin[u] = ++timer;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

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
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    for (int i = 0; i < maxn; i++)
    {
        bit[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        int u;
        std::cin >> u;
        int cnt = get(tin[u]);
        std::cout << cnt << "\n";
        update(tin[u], 1);
        update(tout[u] + 1, -1);
    }

    return 0;
}