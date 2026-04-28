#include <bits/stdc++.h>
#define task "b3"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m, l, r, ans, bs;
std::vector<int> adj[maxn + 7];
int tin[maxn + 7], tout[maxn + 7], tour[maxn + 7], timer;
int d[maxn * 10 + 7], res[maxn + 7], bit[maxn + 7], a[maxn + 7];

struct b3
{
    int l, r, id, k;
} q[maxn + 7];

void dfs(int u, int p)
{
    tin[u] = ++timer;
    tour[timer] = u;
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
    for (; id < n; id = id | (id + 1))
        bit[id] += val;
}

int get(int id)
{
    int ans = 0;
    for (; id >= 0; id = (id & (id + 1)) - 1)
        ans += bit[id];
    return ans;
}

bool cmp(b3 a, b3 b)
{
    if (a.l / bs != b.l / bs)
    {
        return a.l < b.l;
    }
    else
    {
        int id = (a.l + bs - 1) / bs;
        return (id & 1) ? a.r < b.r : a.r > b.r;
    }
}

void mo(int i)
{
    while (l > q[i].l)
    {
        l--;
        update(d[a[tour[l]]], -1);
        d[a[tour[l]]]++;
        update(d[a[tour[l]]], 1);
    }
    while (r < q[i].r)
    {
        r++;
        update(d[a[tour[r]]], -1);
        d[a[tour[r]]]++;
        update(d[a[tour[r]]], 1);
    }
    while (l < q[i].l)
    {
        update(d[a[tour[l]]], -1);
        d[a[tour[l]]]--;
        update(d[a[tour[l]]], 1);
        l++;
    }
    while (r > q[i].r)
    {
        update(d[a[tour[r]]], -1);
        d[a[tour[r]]]--;
        update(d[a[tour[r]]], 1);
        r--;
    }
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

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1);
    bs = sqrt(n);
    for (int i = 1; i <= m; i++)
    {
        int v, k;
        std::cin >> v >> k;
        q[i].l = tin[v];
        q[i].r = tout[v];
        q[i].k = k;
        q[i].id = i;
    }

    std::sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        mo(i);
        res[q[i].id] = get(n) - get(q[i].k - 1);
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << res[i] << "\n";
    }

    return 0;
}
