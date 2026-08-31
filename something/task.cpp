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

int n, m, Q;
int par[maxn + 7], sz[maxn + 7];
ii q[maxn + 7], a[maxn + 7];
bool f[maxn + 7];
std::vector<int> ans;

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
        sz[a] += sz[b];
        par[b] = a;
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m >> Q;

    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }

    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    for (int i = 1; i <= Q; i++)
    {
        std::cin >> q[i].fi >> q[i].se;
        f[q[i].fi] = true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (!f[i])
        {
            union_sets(a[i].fi, a[i].se);
        }
    }

    for (int i = Q; i >= 1; i--)
    {
        ans.pb(sz[find_set(q[i].se)]);
        union_sets(a[q[i].fi].fi, a[q[i].fi].se);
    }

    std::reverse(ans.begin(), ans.end());

    for (auto i : ans)
    {
        std::cout << i << "\n";
    }

    return 0;
}
