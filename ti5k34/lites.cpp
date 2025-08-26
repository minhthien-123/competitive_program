#include <bits/stdc++.h>
#define task "lites"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int st[maxn * 4], a[maxn * 4], n, s, e, i, m, q;

void update(int id, int l, int r, int x, int y) {
    if(r <= l || r <= x || y <= l) return;
    if(x <= l && r <= y){
        a[id]++;
        st[id] = r - l - st[id];
        return;
    }

    int mid = (l + r) / 2;

    update(2 * id + 1, l, mid, x, y);
    update(2 * id + 2, mid, r, x, y);

    st[id] = st[2 * id + 1] + st[2 * id + 2];
    if(a[id] % 2 == 1) st[id] = r - l - st[id];
}

int get(int id, int l, int r, int x, int y){
    if(r <= l || r <= x || y <= l) return 0;
    if(x <= l && r <= y)           return st[id];

    int mid = (l + r) / 2;

    int ans = get(2 * id + 1, l, mid, x, y) + get(2 * id + 2, mid, r, x, y);

    if (a[id] % 2 == 1) ans = std::min(r, y) - std::max(l, x) - ans;

    return ans;
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
    while (m --){
        std::cin >> q >> s >> e;
        if (q == 0) update(0, 0, n, s - 1, e);
        else        std::cout << get(0, 0, n, s - 1, e) << "\n";
    }

    return 0;
}
