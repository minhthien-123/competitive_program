#include <bits/stdc++.h>
#define task "day_con"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int n, q;
int a[maxn];
int st[4 * maxn];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = 1;
        return ;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int l, int r, int u) {
    if (u < l || r < u) {
        return ;
    }
    if (l == r) {
        st[id] = 0;
        return ;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u);
    update(id * 2 + 1, mid + 1, r, u);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
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

    while (q--)
    {
        int k;
        std::cin >> k;
        int ans = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] <= k)
            {
                cnt++;
            }
            else
            {
                ans = std::max(ans, cnt);
                cnt = 0;
            }
        }
        std::cout << std::max(ans, cnt) << "\n";
    }

    return 0;
}
