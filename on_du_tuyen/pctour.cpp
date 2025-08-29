#include <bits/stdc++.h>
#define task "pctour"
#define __Thien_dep_trai__ signed main()
#define ll long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define pll std::pair<ll, ll>
#define vi std::vector<int>
#define vii std::vector<ii>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int maxn = 1e5;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int lg = 20;

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
ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll tmp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return tmp * tmp % mod * x % mod;
    }
}

struct pctour
{
    int u, v;
    ll w, l;
} q[maxn + 7];

std::vector<std::pair<int, ll>> adj[maxn + 7];
/* thêm 1 adjacency global dùng cho trọng số (w + l) */
std::vector<std::pair<int, ll>> adj2[maxn + 7];

int n, m;
ll d1[maxn + 7], dn[maxn + 7];
ll a[maxn + 7], f[maxn + 7];
ll dist[maxn + 7];
bool csub1 = true;
bool csub2 = true;

void dijk(int s, ll d[])
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll, int>>> pq;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll du = cur.fi;
        int u = cur.se;
        if (du != d[u])
        {
            continue;
        }
        for (auto e : adj[u])
        {
            int v = e.fi;
            ll w = e.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

void sub1()
{
    for (int i = 1; i <= m; ++i)
    {
        int u = q[i].u, v = q[i].v;
        ll w = q[i].w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijk(1, d1);
    dijk(n, dn);

    ll ans = inf;
    for (int i = 1; i <= n; ++i)
    {
        if (d1[i] == inf || dn[i] == inf)
        {
            continue;
        }
        if (d1[i] + dn[i] + a[i] < ans)
        {
            ans = d1[i] + dn[i] + a[i];
        }
    }

    if (ans == inf)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << ans << '\n';
    }
}

void sub2()
{
    for (int i = 1; i <= m; ++i)
    {
        int u = q[i].u, v = q[i].v;
        ll w = q[i].w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijk(1, d1);
    dijk(n, dn);

    for (int i = 1; i <= n; i++)
    {
        f[i] = inf;
    }

    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll, int>>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < f[i])
        {
            f[i] = a[i];
            pq.push({f[i], i});
        }
    }
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll du = cur.fi;
        int u = cur.se;
        if (du != f[u])
        {
            continue;
        }
        for (auto e : adj[u])
        {
            int v = e.fi;
            ll w = e.se;
            if (f[v] > f[u] + w)
            {
                f[v] = f[u] + w;
                pq.push({f[v], v});
            }
        }
    }

    ll ans = inf;
    for (int i = 1; i <= n; i++)
    {
        if (d1[i] == inf || dn[i] == inf || f[i] == inf)
        {
            continue;
        }
        ans = std::min(ans, d1[i] + dn[i] + f[i]);
    }

    if (ans == inf)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << ans << '\n';
    }
}

void sub3()
{
    for (int i = 1; i <= m; i++)
    {
        int u = q[i].u, v = q[i].v;
        ll w = q[i].w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijk(1, d1);
    dijk(n, dn);

    for (int i = 1; i <= m; i++)
    {
        int u = q[i].u, v = q[i].v;
        ll w = q[i].w + q[i].l;
        adj2[u].pb({v, w});
        adj2[v].pb({u, w});
    }

    ll ans = inf;


    for (int t = 1; t <= n; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            dist[i] = inf;
        }
        std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll, int>>> pq;
        dist[t] = 0;
        pq.push({0, t});
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            ll du = cur.first;
            int u = cur.second;
            if (du != dist[u])
            {
                continue;
            }
            for (auto e : adj2[u])
            {
                int v = e.first;
                ll w = e.second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (d1[i] == inf || dn[i] == inf || dist[i] == inf)
            {
                continue;
            }
            ans = std::min(ans, d1[i] + dn[i] + dist[i] + a[t]);
        }
    }

    if (ans == inf)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << ans << '\n';
    }
}

__Thien_dep_trai__
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w, l;
        std::cin >> u >> v >> w >> l;
        if (w != l)
        {
            csub1 = false;
        }
        if (l != 0)
        {
            csub2 = false;
        }
        q[i] = {u, v, w, l};
    }

    if (csub1)
    {
        sub1();
    }
    else if (csub2)
    {
        sub2();
    }
    else
    {
        if (n <= 1000)
        {
            sub3();
        }
        else
        {
            std::cout << -1;
        }
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}

/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣾⣿⣿⣿⣿⣷⣦⣤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⡿⡿⡿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⡿⠯⣩⣾⣾⣿⣿⣿⡚⣛⣝⢕⢕⢝⢝⢽⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⡿⣨⣿⣿⣿⣿⠿⣛⡭⢓⣿⣿⣷⣕⢷⣥⠥⢝⣿⣿⣿⡿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⡿⢿⠟⣭⣿⣿⣿⣫⣾⡫⣯⢿⢷⢶⢿⣶⢮⣟⣩⣴⡻⢷⡆⣿⣿⢕⢙⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⡛⡡⠊⣴⣿⣿⣟⢽⢟⣿⣑⣙⣾⠺⣸⡾⡏⣚⡛⣿⣯⡡⢜⣧⢝⣿⣞⡪⡹⣿⣿⣿⡏⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡯⡫⢪⣒⠿⣽⣿⣟⣼⣿⣿⣕⣪⣿⠯⣫⣿⡯⡭⣮⣻⣿⣯⢝⣿⣿⣬⢼⣿⣪⡫⡻⣿⣿⣿⡍⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⣴⡿⡾⠺⡴⣾⣿⣿⢗⣟⣿⣿⠅⣶⣿⣯⢎⣾⡿⡪⣾⡧⣾⣿⠵⢕⣿⣿⣇⢵⣿⣏⡮⠪⣻⣿⡾⡮⡹⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣧⣿⣴⣿⣿⢓⣟⣿⢯⢏⣵⡿⣹⣿⣺⣿⡏⡇⣿⡿⣿⣿⢹⢘⣿⣿⣯⠕⣿⣿⣿⡬⣏⢻⣿⠯⣭⢺⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣟⣼⣿⣿⣿⣿⣿⢵⣿⣿⡯⡼⡲⣿⠗⣻⣿⣾⡟⢽⢺⣿⡧⣿⡿⡧⡣⣿⣿⡿⡟⣿⣿⣿⣷⢻⡼⣿⣿⣿⠲⣻⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣀⠀⣀⣠⡤⣾⣞⣿⣿⣿⣿⣿⣟⡭⣿⣾⣿⠀⠨⣸⡏⠀⢹⣿⣿⠘⡗⢼⣿⣿⢿⢸⡺⠺⣿⣿⣟⡢⣿⣿⣿⣿⣿⣿⢜⣿⣿⡯⣪⣧⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠙⠚⠋⣡⢟⣾⣿⣿⣿⣟⢿⠭⢵⣻⣿⣿⠀⢨⣺⡇⠀⠸⣿⣿⠀⠹⢝⣿⣿⣿⡇⢯⡪⡮⣿⡯⡪⢿⣿⣿⣿⣿⣿⣷⢛⣿⣿⣾⣾⠀⠀⠀⢀⡴⠏⠻⠛⡧⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡼⣻⣿⣿⣿⣿⡟⣗⣳⢼⣏⡻⡩⠿⢤⠼⢾⣿⠀⠀⠹⢿⣇⠀⠳⣽⣿⣿⣷⡈⢮⡪⣻⣟⣒⣻⣿⣿⣿⣿⣿⣿⣕⣿⣿⣿⣿⡆⠀⠀⠘⢷⡆⣠⣙⡇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢯⣽⣿⣟⣥⢹⣵⣿⢮⣿⣷⣴⣿⣶⣾⣦⣤⣄⠀⠀⠀⠈⠉⠁⠀⠈⠙⢻⣛⡻⡎⢻⣽⣯⣆⣯⣿⣿⣿⣿⣿⣿⣧⡺⢟⣱⠞⣦⣀⡀⠀⠈⠙⠉⠉⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠻⡎⣶⣿⣿⣫⣾⣿⠟⠋⠁⠀⠉⠉⠙⠁⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣥⣩⠛⠲⣼⣗⢧⢖⡺⣿⣯⣺⣻⣿⣿⡄⢯⡈⠀⠀⣴⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⢫⣿⣿⣿⣫⣿⣿⡗⠀⢀⠂⡄⠀⠀⠀⠀⠀⠐⠳⠒⠀⠀⠀⠀⠉⠉⠙⠿⢯⣒⣼⣯⢝⣿⣮⡻⣿⣧⣪⡻⣿⡏⡸⠧⠼⣦⠉⢳⠋⢹⡆⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣿⣿⣿⣿⣿⣿⣿⡧⠢⠃⡐⠀⠀⠀⡖⠒⠤⠤⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⡀⡹⢿⣿⠗⣿⣿⣿⣾⣯⡿⡪⡿⣿⣞⡟⣵⠛⠁⠀⠀⠛⣶⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣽⣧⠆⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠈⠉⠙⢳⡄⠀⡰⡜⡠⢁⠽⢿⣽⣿⣿⣿⣿⣿⣮⢮⣻⣗⣿⣬⣛⣿⣀⡽⠛⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣷⣄⠀⠀⠀⠀⠹⡀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⠀⢠⢠⢁⠎⣠⣿⣿⣿⣿⣿⣿⢿⣿⣟⣽⣿⣿⣿⣿⠈⠉⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣰⣻⣿⣿⣿⢻⣿⣿⣿⣕⣿⣿⣿⣿⣷⣦⡀⠀⠀⠁⠀⠀⠀⠀⠀⣠⡤⠖⠁⠀⠀⠀⠁⠘⢎⣸⣺⣿⣿⣿⢿⣿⣽⣿⣿⣿⣿⣿⣿⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢰⣿⡿⣿⣿⢣⣿⢿⣿⢗⣽⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣤⣀⣀⣀⣀⣀⣀⣀⣀⣠⣤⣴⣶⣿⣿⣿⡾⣿⣿⣷⢽⣷⣿⣿⣿⣿⣿⣿⣿⣾⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⣾⣰⣿⣯⢞⣷⣿⣟⣅⣿⣿⣿⠿⠿⠿⠿⠿⠛⠛⠛⠿⣿⣯⡿⡫⡡⠽⣿⠽⠟⣿⣿⣿⣿⣿⣿⣺⣿⣿⣗⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣻⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⣿⣇⣿⣽⢳⣿⣿⠱⣼⡟⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣯⠾⠚⠉⠀⠀⠀⣟⢛⡿⠛⠉⣻⣿⣿⣿⣻⡧⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣧⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⢿⡿⣯⣽⣺⣿⣟⢴⢟⣥⣛⡇⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⠋⠉⠀⠀⠀⠀⠀⠀⣻⠞⠁⠀⠀⣯⣿⣿⣿⣟⣕⣿⡿⣿⣿⣿⣿⣿⣿⣫⡯⣯⣿⣷⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⡺⣺⡿⠿⣾⣿⢣⡭⢿⠀⠹⠖⢶⡀⠀⠀⠀⠀⠀⡼⢭⣉⡀⠀⠀⠀⠀⠀⢀⡜⠁⠀⠀⠀⠸⣿⣿⣿⣿⢷⣗⢿⣿⡿⢋⣹⣿⣿⣿⣿⡪⡿⣾⣺⣿⣄⠀⠀⠀
⠀⠀⠀⢀⡼⣯⣾⣯⣯⣽⣿⣿⠜⢦⡤⠀⠀⢲⡟⠀⠀⠀⠀⠀⢐⡇⠀⠀⠉⠛⠒⠶⠶⣶⠋⠀⠀⠀⠀⠀⣮⣾⣿⣿⣿⣟⣿⣝⢽⠞⣑⢑⣿⣿⣿⣿⡯⣯⣻⣯⣯⣽⣦⠀⠀
⠀⠀⢠⣻⣮⣿⣟⣜⢿⢽⣿⣟⠀⡸⣤⡼⠷⡶⠇⠀⠀⠀⠀⠀⢸⢤⡀⠀⠀⠀⠀⢀⡴⠁⠀⠀⠀⠀⠀⢰⣻⣿⣿⢿⣿⡯⣿⣷⢿⣇⠆⠄⣿⣿⣿⣿⣿⡿⣾⣿⣷⡿⢿⣆⠀
⠀⣰⣿⣷⣿⣿⣷⣝⣵⢽⡿⠫⠰⠸⢸⢸⠸⣿⢇⣀⣠⣄⠀⠀⢸⠀⠀⠀⠀⠉⢉⡟⠀⠀⠀⠀⠀⠀⠀⣇⣿⣿⡏⣾⣿⡿⣿⣿⣺⡻⣴⠙⢾⣿⣿⣿⣿⣷⣿⢿⣿⣿⣺⡻⡇
⢸⡧⢽⣿⣿⣿⣿⠝⣷⠻⠟⢻⡆⠊⡮⠊⣇⠟⣿⡈⠃⠼⣆⠀⠸⠀⠀⠀⠀⢀⠎⠀⠀⠀⠀⠀⠀⠀⢰⣕⢿⣿⢿⢯⣿⣿⣿⣿⣮⡯⡷⣎⣻⣿⣿⣿⣿⣿⣿⣽⣿⣿⣫⡯⣧
⠈⢿⢿⣿⣿⣿⣿⠇⡟⢀⠀⢈⣹⡆⣸⡯⢻⣌⠷⢶⣀⡶⠛⠀⠀⠀⠀⠀⢀⡎⠀⠀⠀⠀⠀⢀⣠⣲⡿⣗⣿⣿⣽⣗⣿⣿⣿⣿⣿⣿⡫⣿⣿⣿⣿⣿⣿⣿⣗⣿⣿⣿⡷⣪⣿
⠀⠀⠛⣿⣿⣿⣿⢵⣽⣟⠦⠞⠁⡊⡪⣿⢨⡿⣯⣳⣭⣤⡀⠀⢠⠀⠀⠀⡘⠀⠀⠀⢀⣤⣾⡿⢋⣥⢾⢷⣷⢿⣇⢿⣏⣿⣿⣿⣿⣯⡿⣯⣺⣿⣿⣿⣵⣿⣿⣿⣿⣿⡯⡫⡎
⠀⠀⠀⠈⢿⣿⣿⡟⣿⣧⣿⣬⠠⢀⠡⢣⣼⡧⠊⠻⣝⣿⣿⢆⢸⠀⠀⢰⠁⢀⣠⣾⡿⠟⣡⠔⠋⠔⡀⡼⣟⣾⣽⣄⣿⣝⣿⣿⣿⣷⣿⣿⢻⣎⣿⣽⣿⣿⡿⣿⣿⣿⡯⣻⠇
*/