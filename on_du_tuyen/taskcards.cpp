#include <bits/stdc++.h>
#define task "main"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m;
ii a[maxn + 7];
ii st[4 * maxn + 7];

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    memset(st, inf, sizeof st);

    for (int i = 1; i <= 4 * n; i++)
    {
        std::cout << st[i].fi << " " << st[i].se << "\n";
    }

    return 0;
}
