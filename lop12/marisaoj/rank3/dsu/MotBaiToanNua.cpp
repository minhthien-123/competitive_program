#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int a[maxn], par[maxn], sz[maxn];
int n, q, d = 0, res = 0;
std::vector<ii> v, querry;
std::vector<int> ans;
bool mp[maxn];

void make_set()
{
    for (int v = 1; v <= n; v++)
    {
        par[v] = v;
        sz[v] = 1;
    }
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

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) std::swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        res = std::max(res, sz[a]);
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

    std::cin >> n >> q;

    make_set();

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        v.pb({a[i], i});
    }

    for (int i = 1, x; i <= q; i++)
    {
        std::cin >> x;
        querry.pb({x, i});
    }

    std::sort(v.begin(), v.end());
    std::sort(querry.begin(), querry.end());

    ans.resize(q);
    res = 0;

    for (auto it : querry){
        int k = it.fi;
        while(d < n && v[d].fi <= k){
            mp[v[d].se] = true;

            if (res == 0) res = 1;

            if (v[d].se > 1 && mp[v[d].se - 1])
            {
                union_sets(v[d].se, v[d].se - 1);
            }
            if (v[d].se < n && mp[v[d].se + 1])
            {
                union_sets(v[d].se, v[d].se + 1);
            }

            d++;
        }
        ans[it.se - 1] = res;
    }

    for (auto it : ans)
    {
        std::cout << it << "\n";
    }

    return 0;
}
