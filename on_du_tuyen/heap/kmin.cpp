#include <bits/stdc++.h>
#define task "kmin"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int m, n, k;
int a[maxn + 7], b[maxn + 7];
std::priority_queue<iii, std::vector<iii>, std::greater<iii>> pq;

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

    std::cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
    }

    std::sort(a + 1, a + m + 1);
    std::sort(b + 1, b + n + 1);

    int lim = std::min(m, k);

    for (int i = 1; i <= lim; i++)
    {
        pq.push({a[i] + b[1], {i, 1}});
    }

    while (k--)
    {
        auto tmp = pq.top();
        pq.pop(); 
        int sum = tmp.fi;
        int i = tmp.se.fi;
        int j = tmp.se.se;

        std::cout << sum << "\n";

        if (j + 1 <= n)
        {
            pq.push({a[i] + b[j + 1], {i, j + 1}});
        }
    }

    return 0;
}
