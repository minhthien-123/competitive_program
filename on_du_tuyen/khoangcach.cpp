#include <bits/stdc++.h>
#define task "khoangcach"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
int a[maxn + 7], st[4 * maxn + 7];
int ans[maxn + 7];
std::unordered_map<int, int> last;
std::vector<ii> query[maxn + 7];

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        st[id] = std::min(st[id], val);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = std::min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return inf;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return std::min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
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
        std::cin >> a[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int l, r;
        std::cin >> l >> r;
        query[r].pb({l, i});
    }

    for (int i = 1; i <= 4 * n; i++)
    {
        st[i] = inf;
    }

    for (int i = 1; i <= n; i++)
    {
        auto it = last.find(a[i]);
        if (it != last.end())
        {
            int pos = it->se;
            update(1, 1, n, pos, i - pos);
        }
        last[a[i]] = i;

        for (auto q : query[i])
        {
            int res = get(1, 1, n, q.fi, i);
            if (res == inf)
            {
                res = -1;
            }
            ans[q.se] = res;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        std::cout << ans[i] << "\n";
    }

    return 0;
}
