#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, m, q;
int sz[maxn], par[maxn];
bool check[maxn];
ii query[maxn], a[maxn];
std::vector<int> ans;

void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_set(int v)
{
    if (par[v] == v)
    {
        return v;
    }
    int p = find_set(par[v]);
    par[v] = p;
    return p;
}

void union_sets(int a, int b)
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

    std::cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    make_set();

    for (int i = 1; i <= q; i++)
    {
        std::cin >> query[i].fi >> query[i].se;
        check[query[i].fi] = true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (!check[i])
        {
            union_sets(a[i].fi, a[i].se);
        }
    }

    for (int i = q; i >= 1; i--)
    {
        ans.pb(sz[find_set(query[i].se)]);
        union_sets(a[query[i].fi].fi, a[query[i].fi].se);
    }

    std::reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        std::cout << i << "\n";
    }

    return 0;
}
