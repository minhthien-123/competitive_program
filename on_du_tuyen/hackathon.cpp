#include <bits/stdc++.h>
#define task "hackathon"
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

struct hackathon
{
    int a, b, c, da, db;
} x[maxn + 7];

int n, m, p, k;
int ans = 0;
int a[maxn + 7], b[maxn + 7];

bool cmp(hackathon a, hackathon b)
{
    return a.a - a.b < b.a - b.b;
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

    std::cin >> m >> n >> p;
    k = m + n + p;

    for (int i = 1; i <= k; i++)
    {
        std::cin >> x[i].a >> x[i].b >> x[i].c;
        x[i].da = x[i].a - x[i].c;
        x[i].db = x[i].b - x[i].c;
        ans += x[i].c;
        a[i] = b[i] = inf;
    }

    std::sort(x + 1, x + k + 1, cmp);
    /*for (int i = 1; i <= k; i++)
    {
        std::cout << x[i].da << " ";
    }
    std::cout << "\n";
    for (int i = 1; i <= k; i++)
    {
        std::cout << x[i].db << " ";
    }
    std::cout << "\n";*/

    std::priority_queue<int> pq;
    int sum = 0;

    for (int i = 1; i <= k; i++)
    {
        int tmp = x[i].da;
        pq.push(tmp);
        sum += tmp;
        if (pq.size() > m)
        {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == m)
        {
            a[i] = sum;
        }
    }

    while (pq.size())
    {
        pq.pop();
    }

    sum = 0;
    for (int i = k; i >= 1; i--)
    {
        int tmp = x[i].db;
        pq.push(tmp);
        sum += tmp;
        if (pq.size() > n)
        {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == n)
        {
            b[i] = sum;
        }
    }

    /*for (int i = 1; i <= k; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    for (int i = 1; i <= k; i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << "\n";*/

    int res = inf;
    for (int i = 1; i <= k; i++)
    {
        //std::cout << a[i] + b[i + 1] << "\n";
        res = std::min(res, a[i] + b[i + 1]);
    }

    std::cout << res + ans;

    return 0;
}
