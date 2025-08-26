#include <bits/stdc++.h>
#define task "task"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n, Q;
int a[maxn + 7];
int par[maxn + 7], sz[maxn + 7], ans[maxn + 7];
int res = 0, id = 0;
std::vector<ii> v, q;
bool f[maxn + 7];

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
        sz[a] += b;
        par[b] = a;
        res = std::max(res, sz[a]);
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> Q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        make_set(i);
        v.pb({a[i], i});
    }

    for (int i = 1; i <= Q; i++)
    {
        int query;
        std::cin >> query;
        q.pb({query, i});
    }

    std::sort(v.begin(), v.end());
    std::sort(q.begin(), q.end());

    for (auto i : q)
    {
        int k = i.fi;
        while (id < n && v[id].fi <= k)
        {
            f[v[id].se] = true;

            if (res == 0)
            {
                res = 1;
            }

            if (v[id].se > 1 && f[v[id].se - 1])
            {
                union_sets(v[id].se, v[id].se - 1);
            }
            if (v[id].se < n && f[v[id].se + 1])
            {
                union_sets(v[id].se, v[id].se + 1);
            }

            id++;
        }

        ans[i.se - 1] = res;
    }

    for (int i = 1; i <= Q; i++)
    {
        std::cout << ans[i] << "\n";
    }

    return 0;
}

