#include <bits/stdc++.h>
#define task "resq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, q;
int par[maxn + 7], sz[maxn + 7], sum[maxn + 7];
int res[maxn + 7], query[maxn + 7];
int a[maxn + 7];
bool flag[maxn + 7], check[maxn + 7];

int find(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = find(par[v]);
    par[v] = p;
    return p;
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            std::swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        sum[a] += sum[b];
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        par[i] = i;
    }
    for (int i = 1; i <= q; i++)
    {
        std::cin >> query[i];
        flag[query[i]] = true;
    }

    int cur = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            check[i] = true;
            par[i] = i;
            sz[i] = 1;
            sum[i] = a[i];
            cur = std::max(cur, sum[i]);
            if (i > 1 && check[i - 1])
            {
                join(i, i - 1);
                cur = std::max(cur, sum[find(i)]);
            }
        }
    }
    res[q] = cur;

    for (int i = q; i >= 1; i--)
    {
        int pos = query[i];
        check[pos] = true;
        par[pos] = pos;
        sz[pos] = 1;
        sum[pos] = a[pos];
        cur = std::max(cur, sum[pos]);

        if (pos > 1 && check[pos - 1])
        {
            join(pos, pos - 1);
        }
        if (pos < n && check[pos + 1])
        {
            join(pos, pos + 1);
        }
        cur = std::max(cur, sum[find(pos)]);
        res[i - 1] = cur;
    }

    for (int i = 1; i <= q; i++)
    {
        std::cout << res[i] << "\n";
    }
    return 0;
}
