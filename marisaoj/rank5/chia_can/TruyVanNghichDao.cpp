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
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;
const int bl = 320;

struct mo
{
    int l, r, pos;
} query[maxn + 7];

int n, q;
int a[maxn + 7];
int bit[maxn + 7], ans[maxn + 7];
int cnt = 0;

void upd(int id, int val)
{
    id++;
    for (; id <= n + 1; id += id & -id)
    {
        bit[id] += val;
    }
}

int get(int id)
{
    int res = 0;
    id++;
    for (; id >= 1; id -= id & -id)
    {
        res += bit[id];
    }
    return res;
}

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

void addRight(int pos)
{
    int x = a[pos];
    int d = get(n) - get(x);
    cnt += d;
    upd(x, 1);
}
void removeRight(int pos)
{
    int x = a[pos];
    int d = get(n) - get(x);
    cnt -= d;
    upd(x, -1);
}
void addLeft(int pos)
{
    int x = a[pos];
    int d = get(x - 1);
    cnt += d;
    upd(x, 1);
}
void removeLeft(int pos)
{
    int x = a[pos];
    int d = get(x - 1);
    cnt -= d;
    upd(x, -1);
}

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

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= q; i++)
    {
        std::cin >> query[i].l >> query[i].r;
        query[i].pos = i;
    }

    std::sort(query + 1, query + q + 1, cmp);

    int l = 1, r = 0;

    for (auto Q : query)
    {
        while (l > Q.l)
        {
            l--;
            addLeft(l);
        }
        while (r < Q.r)
        {
            r++;
            addRight(r);
        }
        while (l < Q.l)
        {
            removeLeft(l);
            l++;
        }
        while (r > Q.r)
        {
            removeRight(r);
            r--;
        }
        ans[Q.pos] = cnt;
    }

    for (int i = 1; i <= q; i++)
    {
        std::cout << ans[i] << "\n";
    }

    return 0;
}
