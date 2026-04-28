#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

struct tree
{
    /* data */
    int zero, one, two;
};


const int maxn = 1e5 + 7;

int n, q;
int a[maxn], lz[4 * maxn];
tree st[4 * maxn];

void build(int id, int l, int r)
{
    if (l == r)
    {
        if (a[l] % 3 == 0)
        {
            st[id].zero = 1;
            st[id].one = st[id].two = 0;
        }
        else if (a[l] % 3 == 1)
        {
            st[id].zero = st[id].two = 0;
            st[id].one = 1;
        }
        else
        {
            st[id].zero = st[id].one = 0;
            st[id].two = 1;
        }
        return;
    }

    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id].zero = st[id * 2].zero + st[id * 2 + 1].zero;
    st[id].one = st[id * 2].one + st[id * 2 + 1].one;
    st[id].two = st[id * 2].two + st[id * 2 + 1].two;
}

void fix(int id, int l, int r)
{
    if (!lz[id]) return;
    int zero = st[id].zero, one = st[id].one, two = st[id].two;
    if (lz[id] % 3 == 1)
    {
        st[id].zero = two;
        st[id].one = zero;
        st[id].two = one;
    }
    else if (lz[id] % 3 == 2)
    {
        st[id].zero = one;
        st[id].one = two;
        st[id].two = zero;
    }

    if (l != r)
    {
        lz[id * 2] += lz[id];
        lz[id * 2 + 1] += lz[id];
    }

    lz[id] = 0;
}

void update(int id, int l, int r, int u, int v)
{
    fix(id, l, r);
    if (l > v || r < u)
        return;
    if (l >= u && r <= v)
    {
        lz[id]++;
        fix(id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    st[id].zero = st[id * 2].zero + st[id * 2 + 1].zero;
    st[id].one = st[id * 2].one + st[id * 2 + 1].one;
    st[id].two = st[id * 2].two + st[id * 2 + 1].two;
}

tree get(int id, int l, int r, int u, int v)
{
    fix(id, l, r);
    if (v < l || r < u)
    {
        return {0, 0, 0};
    }
    if (l >= u && r <= v)
    {
        return st[id];
    }

    int mid = (l + r) >> 1;
    tree get1 = get(id * 2, l, mid, u, v);
    tree get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return {get1.zero + get2.zero, get1.one + get2.one, get1.two + get2.two};
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    build(1, 1, n);

    while (q--)
    {
        int type, l, r;
        std::cin >> type >> l >> r;

        if (type == 1)
        {
            update(1, 1, n, l, r);
        }
        else
        {
            std::cout << get(1, 1, n, l, r).zero << "\n";
        }
    }

    return 0;
}
