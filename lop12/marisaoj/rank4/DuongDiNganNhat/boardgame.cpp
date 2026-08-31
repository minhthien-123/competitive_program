#include <bits/stdc++.h>
#define task ""
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

int n, l, r, u, x, v;
std::vector<ii> adj[2 * maxn + 7];
int a[maxn + 7], d[2 * maxn + 7];
std::map<int, int> mp;

void dijk(int s)
{
    std::priority_queue<ii, std::vector<ii>, std::greater<>> pq;
    for (int i = 1; i <= 2 * n; i++)
    {
        d[i] = inf;
    }
    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int cost = pq.top().fi;
        int u    = pq.top().se;
        pq.pop();
        if (d[u] < cost)
        {
            continue;
        }

        for (auto e : adj[u])
        {
            int v = e.fi;
            int w = e.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
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

    std::cin >> n >> l >> r >> x >> u >> v;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        adj[i].pb({i + 1, r});
        adj[i + 1].pb({i, l});
    }

    int pos = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (!mp.count(a[i]))
        {
            mp[a[i]] = pos++;
        }
        int tmp = mp[a[i]];
        adj[i].pb({tmp, x});
        adj[tmp].pb({i, 0});
    }

    dijk(u);

    std::cout << d[v];

    return 0;
}
