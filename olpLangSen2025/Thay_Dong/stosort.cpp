#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

struct Fenwick
{
    int n;
    std::vector<int> bit;
    Fenwick(int _n) : n(_n), bit(n + 1, 0) {}

    void update(int i, int val)
    {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    int query(int i)
    {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    int get(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

int a[maxn + 7], pos[maxn + 7];

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

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        pos[a[i]] = i;
    }
    Fenwick fw(n);

    for (int i = 1; i <= n; i++)
    {
        fw.update(i, 1);
    }

    int d = 0;
    int cur = n;

    for (int j = 1; j <= n; j++)
    {
        d += fw.get(std::min(cur, pos[j]), std::max(cur, pos[j]));
        cur = pos[j];
        fw.update(pos[j], -1);
    }

    std::cout << d;

    return 0;
}
