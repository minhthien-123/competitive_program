#include <bits/stdc++.h>
#define task "cses2420"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

const int base = 31;

std::string s;
int n, k;

int p[maxn + 7], h1[maxn + 7], h2[maxn + 7];

int get(int l, int r, int h[])
{
    return (h[r] - h[l - 1] * p[r - l + 1] + mod * mod) % mod;
}

struct tree
{
    int h1, h2, len;
} st[4 * maxn + 7];

tree merge(tree a, tree b)
{
    tree res;
    res.len = a.len + b.len;
    res.h1 = ((a.h1 * p[b.len] + mod % mod) + b.h1) % mod;
    res.h2 = ((b.h2 * p[a.len] + mod % mod) + a.h2) % mod;
    return res;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        int tmp = s[l - 1] - 'a' + 1;
        st[id] = {tmp, tmp, 1};
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        st[id] = {val, val, 1};
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

tree get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return {0, 0, 0};
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }

    int mid = (l + r) / 2;
    tree tree1 = get(id * 2, l, mid, u, v);
    tree tree2 = get(id * 2 + 1, mid + 1, r, u, v);
    return merge(tree1, tree2);
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

    std::cin >> n >> k;
    std::cin >> s;

    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = (p[i - 1] * base) % mod;
    }

    build(1, 1, n);
    while (k--)
    {
        int type;
        std::cin >> type;
        if (type == 1)
        {
            int pos;
            char c;
            std::cin >> pos >> c;
            update(1, 1, n, pos, c - 'a' + 1);
        }
        else
        {
            int u, v;
            std::cin >> u >> v;
            tree ans = get(1, 1, n, u, v);
            if (ans.h1 == ans.h2)
            {
                std::cout << "YES\n";
            }
            else
            {
                std::cout << "NO\n";
            }
        }
    }

    return 0;
}
