#include <bits/stdc++.h>
#define task "main"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

std::string s;
int m;

struct tree
{
    int s, l, r;
}st[4 * maxn + 7];

tree merge(tree a, tree b)
{
    tree res;
    int tmp = std::min(a.l, b.r);
    res.s = a.s + b.s + tmp;
    res.l = a.l + b.l - tmp;
    res.r = a.r + b.r - tmp;
    return res;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        if (s[l] == '(')
        {
            st[id].s = st[id].r = 0;
            st[id].l = 1;
        }
        else
        {
            st[id].s = st[id].l = 0;
            st[id].r = 1;
        }
        return;
    }

    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

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
    int mid = (l + r) >> 1;
    tree left = get(id * 2, l, mid, u, v);
    tree right = get(id * 2 + 1, mid + 1, r, u, v);
    return merge(left, right);
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

    std::cin >> s;

    int n = s.size();

    build(1, 0, n - 1);

    std::cin >> m;
    while (m--)
    {
        int x, y;
        std::cin >> x >> y;
        tree res = get(1, 0, n - 1, x - 1, y - 1);
        std::cout << res.s * 2 << '\n';
    }

    return 0;
}
