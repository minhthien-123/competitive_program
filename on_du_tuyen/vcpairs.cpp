#include <bits/stdc++.h>
#define task "vcpairs"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
int a[maxn + 5];
std::unordered_map<int, int> cnt[maxn + 7];
int par[maxn + 5], sz[maxn + 5];
int ans = 0;

void init(int i)
{
    par[i] = i;
    sz[i] = 1;
    cnt[i][a[i]] = 1;
}

int acs(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = acs(par[v]);
    par[v] = p;
    return p;
}

void join(int u, int v)
{
    u = acs(u);
    v = acs(v);
    if (u == v)
    {
        return;
    }
    if (sz[u] < sz[v])
    {
        std::swap(u, v);
    }
    for (auto p : cnt[v])
    {
        auto it = cnt[u].find(p.fi);
        if (it != cnt[u].end())
        {
            ans += it->se * p.se;
        }
    }
    for (auto p : cnt[v])
    {
        cnt[u][p.fi] += p.se;
    }
    par[v] = u;
    sz[u] += sz[v];
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

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

    for (int i = 1; i <= n; i++)
    {
        init(i);
    }

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        join(u, v);
        std::cout << ans << '\n';
    }

    return 0;
}
