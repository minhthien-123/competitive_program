#include <bits/stdc++.h>
#define task "tours"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e4;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

bool vis[maxn];
std::vector<int> adj[maxn + 7], vec;
std::vector<std::vector<int>> ans;
int n, m, res = 0, color[maxn + 7], par[maxn + 7];
bool stop;

void dfs(int u)
{
    color[u] = 1;
    for (auto v : adj[u])
    {
        if (par[u] == v)
        {
            continue;
        }
        if (color[v] == 0)
        {
            par[v] = u;
            dfs(v);
        }
        else if (color[v] == 1)
        {
            vec.clear();
            res++;
            int tmp = u;
            vec.pb(tmp);
            while (tmp != v)
            {
                tmp = par[tmp];
                vec.pb(tmp);
            }
            std::reverse(vec.begin(), vec.end());
            vec.pb(v);
            ans.pb(vec);
        }
    }
    color[u] = 2;
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
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            dfs(i);
        }
    }

    std::cout << res << "\n";
    for (int i = 0; i < res; i++)
    {
        for (auto j : ans[i])
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }

    return 0;
}