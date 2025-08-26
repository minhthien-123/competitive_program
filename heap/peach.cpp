#include <bits/stdc++.h>
#define task "peach"
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

struct peach
{
    int val, time;
} f[maxn + 7];

bool cmp(peach a, peach b)
{
    return (a.time < b.time) || (a.time == b.time && a.val > b.val);
}

struct grter
{
    bool operator()(peach a, peach b)
    {
        return (a.val < b.val) || (a.val == b.val && a.time > b.time);
    }
};

int n, a, b, k;
std::priority_queue<peach, std::vector<peach>, grter> pq;

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

    std::cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> f[i].time >> f[i].val;
    }
    std::sort(f + 1, f + n + 1, cmp);

    k = 1;
    int res = 0;
    int t = a;

    while (k <= n || !pq.empty())
    {
        if (pq.empty())
        {
            t = std::max(t, f[k].time);
            if (t >= b)
            {
                break;
            }
        }

        while (k <= n && f[k].time <= t)
        {
            pq.push(f[k]);
            k++;
        }

        if (t >= b)
        {
            break;
        }
        
        res += pq.top().val;
        pq.pop();
        t++;
    }

    std::cout << res;
    return 0;
}
