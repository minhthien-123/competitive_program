#include <bits/stdc++.h>
#define task "homework"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
const int inf  = 1e18;

int n, m;
int t[maxn], f[maxn], d[maxn];
std::vector<int> adj[maxn];
bool flag[maxn];

int calc(int k)
{
    std::queue<int> q;
    std::vector<int> tmp;
    for (int i = 1; i <= n; i++)
    {
        f[i] = d[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0 && i != k)
        {
            q.push(i);
        }
    }

    while (q.size())
    {
        int u = q.front();
        q.pop();
        tmp.pb(u);

        for (auto v : adj[u])
        {
            if (v == k)
            {
                continue;
            }
            f[v]--;
            if (f[v] == 0)
            {
                q.push(v);
            }
        }
    }

    // std::cout << k << " " << tmp.size() << "\n";
    // for (int u : tmp)
    // {
    //     std::cout << t[u] << " ";
    // }
    // std::cout << "\n";

    if (tmp.size() != n - 1)
    {
        return inf;
    }

    int res = 0;
    for (int u : tmp)
    {
        res += t[u];
    }

    return res;
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
        std::cin >> t[i];
    }

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        d[v]++;
    }

    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        ans = std::min(ans, calc(i));
    }

    //std::cout << calc(4) << "\n";

    std::cout << ans;

    return 0;
}
