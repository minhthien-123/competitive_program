#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf  = 1e18;

int n, k;
int par[maxn];
std::vector<ii> adj[maxn];
int dp[4 * maxn], lz[4 * maxn];

bool cmp(ii x, ii y)
{
    return x.se > y.se;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        par[l] = id;
        return;
    }

    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}

void fix(int id)
{
    if (lz[id])
    {
        dp[id] = std::min(lz[id], dp[id]);
        lz[id * 2] = std::min(lz[id], lz[id * 2]);
        lz[id * 2 + 1] = std::min(lz[id], lz[id * 2 + 1]);
        lz[id] = inf;
    }
}

void update(int id, int l, int r, int u, int v, int val)
{
    fix(id);
    if (v < l || r < u) return;
    if (l >= u && r <= v)
    {
        lz[id] = std::min(lz[id], val);
        fix(id);
        return;
    }

    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    dp[id] = std::max(dp[id * 2], dp[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    fix(id);
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return dp[id];
    int mid = (l + r) >> 1;
    return std::max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
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

    std::cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        int l, r, c;
        std::cin >> l >> r >> c;
        adj[r].pb({l, c});
    }

    for (int i = 0; i <= maxn; i++)
    {
        if (!adj[i].empty())
        {
            std::sort(adj[i].begin(), adj[i].end(), cmp);
        }
    }

    std::fill(dp, dp + 4 * maxn, inf);
    std::fill(lz, lz + 4 * maxn, inf);

    build(1, 1, n);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int l = adj[i][j].fi, c = adj[i][j].se;
            int tmp = par[i];
            dp[tmp] = std::min(dp[tmp], get(1, 1, n, 1, l - 1) + c);
            update(1, 1, n, l, i - 1, dp[tmp]);
        }
    }

    if (dp[par[n]] == inf)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << dp[par[n]];
    }

    return 0;
}
