#include <bits/stdc++.h>
#define task "circuit"
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

int n, m;
std::vector<int> adj[maxn + 7], ans;
bool vis[maxn + 7];
int par[maxn + 7], flag[maxn + 7];
std::map<ii, int> d;

bool dfs(int u)
{
    vis[u] = 1;
    flag[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            par[v] = u;
            if (dfs(v))
            {
                return 1;
            }
        }
        else if (flag[v])
        {
            ans.pb(v);
            int e = u;
            while (e != v)
            {
                ans.pb(e);
                e = par[e];
            }
            ans.pb(v);
            std::reverse(ans.begin(), ans.end());
            return 1;
        }
    }

    flag[u] = 0;
    return 0;
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

    memset(vis, 0, sizeof vis);
    memset(flag, 0, sizeof flag);
    memset(par, -1, sizeof par);

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        d[{u, v}] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && dfs(i))
        {
            break;
        }
    }

    if (!ans.empty())
    {
        std::cout << "YES\n";
        for (int i = 1; i < (int)ans.size(); i++)
        {
            std::cout << d[{ans[i - 1], ans[i]}] << " ";
        }
    }
    else
    {
        std::cout << "NO";
    }

    return 0;
}
