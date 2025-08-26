#include <bits/stdc++.h>
#define task "FINDSEQ"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

struct findseq
{
    int l, r, k;
};

int n, m;
int a[maxn + 7];
int par[maxn + 7];
int st[4 * maxn + 7];
std::vector<findseq> query;

int find(int v)
{
    if (v > n)
        return v;
    return par[v] == v ? v : par[v] = find(par[v]);
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = std::max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return -inf;
    if (u <= l && r <= v)
        return st[id];
    int mid = (l + r) >> 1;
    return std::max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

bool cmp(findseq x, findseq y)
{
    return x.k < y.k;
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

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        a[i] = -inf;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r, k;
        std::cin >> l >> r >> k;
        query.pb({l, r, k});
    }

    std::sort(query.begin(), query.end(), cmp);

    for (auto q : query)
    {
        int pos = find(q.l);
        while (pos <= q.r)
        {
            a[pos] = q.k;
            par[pos] = pos + 1;
            pos = find(pos);
        }
    }

    build(1, 1, n);
    for (auto q : query)
    {
        if (q.k != get(1, 1, n, q.l, q.r))
        {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES\n";
    return 0;
}
