#include <bits/stdc++.h>
#define task "dquery"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

struct tree
{
    int beg, en, type, dex;
};

const int maxn = 1e5 + 7;

int n, q;
int res[maxn], bit[2 * maxn], f[maxn];
tree a[2 * maxn];

bool cmp(tree x, tree y) {
    if (x.en != y.en)
    {
        return x.en < y.en;
    }
    return x.type < y.type;
}

void update(int id, int val)
{
    for (id; id <= n; id += id & (-id))
    {
        bit[id] += val;
    }
}

int get(int id)
{
    int sum = 0;
    for (id; id > 0; id -= id & (-id))
    {
        sum += bit[id];
    }
    return sum;
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
        std::cin >> a[i].beg;
        a[i].en = i;
        a[i].type = -1;
        a[i].dex = 0;
    }

    for (int i = 1; i <= q; i++)
    {
        std::cin >> a[i + n].beg >> a[i + n].en;
        a[i + n].dex = i;
        a[i + n].type = 0;
    }

    std::sort(a + 1, a + n + q + 1, cmp);

    for (int i = 1; i <= n + q; i++)
    {
        if (a[i].type == -1)
        {
            update(a[i].en, 1);
            if (f[a[i].beg] > 0)
            {
                update(f[a[i].beg], -1);
            }
            f[a[i].beg] = a[i].en;
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
