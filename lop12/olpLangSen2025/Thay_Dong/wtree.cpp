#include <bits/stdc++.h>
#define task "wtree"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, s;
int a[maxn + 7];
int tin[maxn + 7], tout[maxn + 7], timer;
int p[maxn + 7];
bool dp[maxn + 7][maxn + 7], trace[maxn + 7][maxn + 7];
std::vector<int> adj[maxn + 7];

struct wtree
{
    int l, r, w, id;
};

std::vector<wtree> vec;

void dfs(int u, int p)
{
    tin[u] = ++timer;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs(v, u);
        a[u] += a[v];
    }
    tout[u] = timer;
}

bool cmp(wtree x, wtree y)
{
    if (x.r != y.r)
    {
        return x.r < y.r;
    }
    return x.l < y.l;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> s;
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

    vec.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        vec.pb({tin[i], tout[i], a[i], i});
    }
    std::sort(vec.begin(), vec.end(), cmp);

    std::vector<int> out;
    out.reserve(n);
    for (auto w : vec)
    {
        out.pb(w.r);
    }

    for (int i = 1; i <= n; i++)
    {
        int l = vec[i - 1].l;
        p[i] = std::lower_bound(out.begin(), out.end(), l) - out.begin();
    }

    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        int val = vec[i - 1].w;
        for (int sum = 0; sum <= s; sum++)
        {
            if (dp[i - 1][sum])
            {
                dp[i][sum] = true;
                trace[i][sum] = 0;
            }
            if (sum >= val && dp[p[i]][sum - val])
            {
                dp[i][sum] = true;
                trace[i][sum] = 1;
            }
        }
    }

    if (!dp[n][s])
    {
        std::cout << -1;
        return 0;
    }

    std::vector<int> res;
    int i = n, sum = s;
    while (i > 0 && sum > 0)
    {
        if (trace[i][sum])
        {
            res.pb(vec[i - 1].id);
            sum -= vec[i - 1].w;
            i = p[i];
        }
        else
        {
            i--;
        }
    }
    std::cout << res.size() << '\n';
    for (int x : res)
    {
        std::cout << x << ' ';
    }
    return 0;
}
