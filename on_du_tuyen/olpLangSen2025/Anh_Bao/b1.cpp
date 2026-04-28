#include <bits/stdc++.h>
#define task "b1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, t;
int a[maxn + 7];
int st[4 * maxn + 7];
std::map<int, std::vector<int>> mp;

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = std::__gcd(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return std::__gcd(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
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
        std::cin >> a[i];
        mp[a[i]].pb(i);
    }
    build(1, 1, n);
    std::cin >> t;
    while (t--)
    {
        int l, r;
        std::cin >> l >> r;
        int x = get(1, 1, n, l, r);
        int L = std::lower_bound(mp[x].begin(), mp[x].end(), l) - mp[x].begin();
        int R = std::upper_bound(mp[x].begin(), mp[x].end(), r) - mp[x].begin();
        std::cout << r - l + 1 - (R - L) << "\n";
    }

    return 0;
}
