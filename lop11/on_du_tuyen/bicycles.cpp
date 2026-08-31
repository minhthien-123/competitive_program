#include <bits/stdc++.h>
#define task "bicycles"
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

int n, m;
int a[maxn + 7];
std::deque<int> dq;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        dq.pb(i);
    }

    int d = 0;
    while (dq.size())
    {
        if (a[dq.front()] + a[dq.back()] <= m)
        {
            d++;
            dq.pop_back();
            if (dq.size())
            {
                dq.pop_front();
            }
        }
        else
        {
            d++;
            dq.pop_back();
        }
    }

    std::cout << d;

    return 0;
}
