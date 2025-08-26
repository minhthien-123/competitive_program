#include <bits/stdc++.h>
#define task "closing"
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

int n, m;
int par[maxn + 7], sz[maxn + 7];
std::vector<int> adj[maxn + 7];
int a[maxn + 7], ans[maxn + 7];
bool f[maxn + 7];

void init(int v)
{
    par[v] = v;
    sz[v] = 1;
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

bool join(int a, int b)
{
    a = acs(a);
    b = acs(b);
    if (a == b)
    {
        return false;
    }
    if (sz[a] < sz[b])
    {
        std::swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
    return true;
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
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        init(i);
    }

    int cnt = 0;

    for (int i = n; i >= 1; i--)
    {
        f[a[i]] = true;
        cnt++;

        for (int v : adj[a[i]])
        {
            if (f[v] && join(a[i], v))
            {
                cnt--;
            }
        }

        ans[i] = cnt;
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << "\n";
    }

    return 0;
}
