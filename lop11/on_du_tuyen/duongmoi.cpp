#include <bits/stdc++.h>
#define task "duongmoi"
#define _Thiendeptrai_ signed main()
#define ll long long
#define ii std::pair<ll, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5005;
const ll inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;
const int lg   = 20;

ll add(ll x, ll y)
{
    return (x + y + 2 * mod) % mod;
}
ll sub(ll x, ll y)
{
    return (x - y + 2 * mod) % mod;
}
ll mul(ll x, ll y)
{
    return (x * y) % mod;
}

std::vector<std::pair<int, ll>> adj[maxn + 7];
int n, m;
int s, t, l;
ll k;
ll ds[maxn + 7], dt[maxn + 7];

void dijk(int src, ll d[])
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }

    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> pq;
    d[src] = 0;
    pq.push({d[src], src});

    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        ll du = tmp.first;
        int u  = tmp.second;
        if (du != d[u])
        {
            continue;
        }

        for (auto e : adj[u])
        {
            int v = e.first;
            ll w  = e.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

_Thiendeptrai_
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
            std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m >> s >> t >> l >> k;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        std::cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijk(s, ds);
    dijk(t, dt);

    if (ds[t] <= k)
    {
        std::cout << (ll)n * (n - 1) / 2;
        exit(0);
    }

    ll lim = k - l;
    if (lim < 0)
    {
        std::cout << 0;
        exit(0);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            bool check = false;
            if (ds[i] != inf && dt[j] != inf && ds[i] + dt[j] <= lim)
            {
                check = true;
            }
            else if (ds[j] != inf && dt[i] != inf && ds[j] + dt[i] <= lim)
            {
                check = true;
            }
            if (check)
            {
                ans++;
            }
        }
    }

    std::cout << ans;

    return 0;
}
