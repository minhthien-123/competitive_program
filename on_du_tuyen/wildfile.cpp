#include <bits/stdc++.h>
#define task "WILDLIFE"
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

int n, m;
int par[maxn + 7], sz[maxn + 7];

void init(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int find(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = find(par[v]);
    par[v] = p;
    return p;
}

bool join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            std::swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}

struct wildlife
{
    int u, v, id, w;
};

std::vector<wildlife> vec;
std::vector<ii> adj[maxn + 7];
int pe[maxn + 7];
bool vis[maxn + 7];
int a[maxn + 7];

bool cmp(wildlife x, wildlife y)
{
    return x.w < y.w;
}

bool dfs(int s, int t)
{
    if (s == t)
    {
        return true;
    }
    vis[s] = true;
    for (auto tmp : adj[s])
    {
        int v = tmp.fi;
        if (vis[v])
        {
            continue;
        }
        pe[v] = tmp.se;
        if (dfs(v, t))
        {
            return true;
        }
    }

    return false;
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        init(i);
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        int w = llabs(a[u] - a[v]);
        vec.pb({u, v, i, w});
    }

    std::sort(vec.begin(), vec.end(), cmp);

    int ans = 0;

    for (auto e : vec)
    {
        if (join(e.u, e.v))
        {
            adj[e.u].pb({e.v, e.id});
            adj[e.v].pb({e.u, e.id});
        }

        if (find(1) == find(n))
        {
            ans = e.w;
            break;
        }
    }

    dfs(1, n);

    int tmp = n;
    std::vector<int> path;
    while (tmp != 1)
    {
        int id = pe[tmp];
        path.pb(id);

        int trace = -1;
        for (auto tmp : adj[tmp])
        {
            if (tmp.se == id)
            {
                trace = tmp.fi;
                break;
            }
        }

        tmp = trace;
    }

    std::reverse(path.begin(), path.end());

    std::cout << ans << "\n";
    for (int i : path)
    {
        std::cout << i << " ";
    }

    return 0;
}
