#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

struct data
{
    int beg, en, val, type, dex;
};

const int maxn = 2e5 + 7;

data a[maxn];
int bit[maxn], res[maxn], n, q;

bool cmp(data x, data y)
{
    return (x.val > y.val) || ((x.val == y.val) && (x.type > y.type));
}

void update(int id)
{
    for (id; id <= n; id += id & (-id))
    {
        bit[id]++;
    }
}

int get(int id)
{
    int ans = 0;
    for (id; id > 0; id -= id & (-id))
    {
        ans += bit[id];
    }

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

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].val;
        a[i].beg = a[i].en = i;
        a[i].type = -1;
    }

    for (int i = 1; i <= q; i++)
    {
        //std::cin >> a[i + n].beg >> a[i + n].en >> a[i + n].val;
        a[i + n].beg = 1;
        a[i + n].en  = n;
        std::cin >> a[i + n].val;
        a[i + n].dex = i;
    }

    std::sort(a + 1, a + n + q + 1, cmp);

    for (int i = 1; i <= n + q; i++)
    {
        if (a[i].type == -1)
        {
            update(a[i].beg);
        }
        else
        {
            res[a[i].dex] = get(a[i].en) - get(a[i].beg - 1);
        }
    }

    for (int i = 1; i <= q; i++)
    {
        std::cout << res[i] << "\n";
    }

    return 0;
}