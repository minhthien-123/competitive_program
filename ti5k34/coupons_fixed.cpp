#include <bits/stdc++.h>
#define task "coupons"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5;
const int inf = 2e9;

int n, m, k, sum = 0, f[maxn + 7];
struct coupons
{
    int a, b, c;
} x[maxn + 7];

struct cmp
{
    bool operator()(ii a, ii b)
    {
        return a.fi > b.fi;
    }
};

std::priority_queue<ii, std::vector<ii>, cmp> qa, qb, qc;

bool cmp1(coupons u, coupons v)
{
    return u.b < v.b;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::ifstream(task ".inp"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 0;
        std::cin >> x[i].a >> x[i].b;
        x[i].c = x[i].a - x[i].b;
    }

    std::sort(x + 1, x + n + 1, cmp1);
    int res = 0;
    for (int i = 1; i <= k; i++)
    {
        if (sum + x[i].b > m)
        {
            break;
        }
        sum += x[i].b;
        res++;
    }

    for (int i = 1; i <= k; i++)
    {
        qc.push({x[i].c, i});
        f[i] = 1;
    }

    for (int i = k + 1; i <= n; i++)
    {
        qa.push({x[i].a, i});
        qb.push({x[i].b, i});
    }

    while (true)
    {
        while (!qa.empty() && f[qa.top().se])
        {
            qa.pop();
        }
        while (!qb.empty() && f[qb.top().se])
        {
            qb.pop();
        }

        int cost1 = inf, cost2 = inf;
        int id1 = -1, id2 = -1;

        if (!qa.empty())
        {
            cost1 = qa.top().fi;
            id1 = qa.top().se;
        }

        if (!qb.empty() && !qc.empty())
        {
            cost2 = qb.top().fi + qc.top().fi;
            id2 = qb.top().se;
        }

        int mn = std::min(cost1, cost2);
        if (mn == inf || sum + mn > m)
        {
            break;
        }

        sum += mn;
        res++;

        if (cost1 <= cost2)
        {
            f[id1] = 1;
            qa.pop();
        }
        else
        {
            f[id2] = 1;
            qb.pop();
            qc.pop();
            qc.push({x[id2].c, id2});
        }
    }

    std::cout << res;
    return 0;
}
