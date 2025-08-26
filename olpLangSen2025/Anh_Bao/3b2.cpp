#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int t;
int n;
int a[maxn + 7];
int cnt;
std::vector<int> adj[maxn + 7];

void dfs(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }

        dfs(v, u);
        if (a[v] == 1)
        {
            a[v] ^= 1;
            a[u] ^= 1;
            cnt++;
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

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
            adj[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            std::cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        cnt = 0;

        dfs(1, -1);

        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i])
            {
                flag = false;
            }
        }

        if (flag)
        {
            std::cout << cnt;
        }
        else
        {
            std::cout << -1;
        }
        std::cout << "\n";
    }

    return 0;
}
