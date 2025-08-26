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

int n, m;
int a[maxn + 7];
int st[4 * maxn + 7];

int ans = 0;

void build(int id, int l, int r, bool flag)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    if (flag)
    {
        build(2 * id, l, mid, 0);
        build(2 * id + 1, mid + 1, r, 0);
        st[id] = st[2 * id] | st[2 * id + 1];
    }
    else
    {
        build(2 * id, l, mid, 1);
        build(2 * id + 1, mid + 1, r, 1);
        st[id] = st[2 * id] ^ st[2 * id + 1];
    }
}

void update(int id, int l, int r, int pos, int val, bool flag)
{
    if (pos < l || r < pos) return;
    if (l == r)
    {
        st[id] = val;
        return;
    }

    int mid = (l + r) >> 1;
    update(2 * id, l, mid, pos, val, !flag);
    update(2 * id + 1, mid + 1, r, pos, val, !flag);

    if (flag)
    {
        st[id] = st[2 * id] | st[2 * id + 1];
    }
    else
    {
        st[id] = st[2 * id] ^ st[2 * id + 1];
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

    std::cin >> n >> m;
    bool flag = n % 2;
    n = 1 << n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    build(1, 1, n, flag);

    std::cout << st[1] << "\n";

    while (m--)
    {
        int p, b;
        std::cin >> p >> b;
        update(1, 1, n, p, b, flag);
        std::cout << st[1] << "\n";
    }

    return 0;
}
