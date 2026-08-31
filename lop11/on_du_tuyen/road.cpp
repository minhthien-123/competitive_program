#include <bits/stdc++.h>
#define task "road"
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
ii a[maxn + 7];
int par[maxn + 7], sz[maxn + 7];

void make_set(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = find_set(par[v]);
    par[v] = p;
    return p;
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            std::swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];

        return true;
    }

    return false;
}

struct road
{
    int u, v, w;
};

bool cmp(road a, road b)
{
    return a.w < b.w;
}

std::vector<road> vec;
std::vector<ii> ans;

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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
        make_set(i);
    }

    std::cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        union_sets(u, v);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int dx = a[i].fi - a[j].fi;
            int dy = a[i].se - a[j].se;
            vec.pb({i, j, dx * dx + dy * dy});
        }
    }
    std::sort(vec.begin(), vec.end(), cmp);

    for (auto i : vec)
    {
        if (union_sets(i.u, i.v))
        {
            ans.pb({i.u, i.v});
        }
    }

    std::cout << ans.size() << "\n";
    for (auto i : ans)
    {
        std::cout << i.fi << ' ' << i.se << "\n";
    }

    return 0;
}