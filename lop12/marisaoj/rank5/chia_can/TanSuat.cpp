#include <bits/stdc++.h>
#define task ""
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
const int bl   = 320;

struct mo
{
    int l, r, x, pos;
} query[maxn + 7];

int n, q;
int a[maxn + 7];
int ans[maxn + 7], f[maxn + 7], cnt[maxn + 7];

bool cmp(mo a, mo b)
{
    if (a.l / bl != b.l / bl)
    {
        return a.l < b.l;
    }
    else
    {
        return a.r < b.r;
    }
}

void add_val(int pos)
{
    int val = a[pos];
    int last = f[val];
    if (last > 0)
    {
        cnt[last]--;
    }
    f[val]++;
    cnt[f[val]]++;
}

void remove_val(int pos)
{
    int val = a[pos];
    int last = f[val];
    cnt[last]--;
    f[val]--;
    if (f[val] > 0)
    {
        cnt[f[val]]++;
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

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= q; i++)
    {
        std::cin >> query[i].l >> query[i].r >> query[i].x;
        query[i].pos = i;
    }

    std::sort(query + 1, query + q + 1, cmp);

    int l = 0, r = -1;

    for (auto q : query)
    {
        while (l > q.l)
        {
            l--;
            add_val(l);
        }
        while (r < q.r)
        {
            r++;
            add_val(r);
        }
        while (l < q.l)
        {
            remove_val(l);
            l++;
        }
        while (r > q.r)
        {
            remove_val(r);
            r--;
        }

        ans[q.pos] = cnt[q.x];
    }

    for (int i = 1; i <= q; i++)
    {
        std::cout << ans[i] << "\n";
    }

    return 0;
}
