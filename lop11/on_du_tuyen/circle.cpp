#include <bits/stdc++.h>
#define task "circles"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
std::vector<int> adj[maxn + 7], v, f, ans[maxn + 7];
int a[maxn + 7], pos[maxn + 7], b[maxn + 7], nxt[maxn + 7];
bool vis[maxn + 7];

void dfs(int u)
{
    if (vis[u])
    {
        return;
    }
    v.pb(u);
    vis[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        pos[a[i]] = i;
        b[i] = a[i];
        adj[i].pb(a[i]);
    }

    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        v.clear();
        dfs(i);
        if (!v.empty())
        {
            m++;
            ans[m] = v;
        }
        if (!v.empty())
        {
            //std::cout << "\n";
        }
    }

    v.clear();
    for (int i = 1; i <= m; i++)
    {
        if (ans[i].size() > 1 || a[ans[i][0]] == ans[i][0])
        {
            v.pb(i);
        }
        else
        {
            f.pb(i);
        }
    }

    if (v.size() > 1)
    {
        std::cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++)
        {
            int s = v[i];
            int t = v[(i + 1) % v.size()];
            std::cout << ans[s].back() << ' ' << ans[t].front() << "\n";
        }
    }
    else if (v.size() == 1)
    {
        if (f.empty())
        {
            std::cout << 0;
        }
        else
        {
            std::cout << 1 << "\n";
            std::cout << ans[f[0]][0] << " " << ans[v[0]][0];
        }
    }
    else
    {
        std::cout << 1 << "\n" << ans[1][0] << " " << ans[1][0];
    }

    return 0;
}