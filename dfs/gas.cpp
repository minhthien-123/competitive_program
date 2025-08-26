#include <bits/stdc++.h>
#define task "gas"
#define int long long

const int maxn = 1e6 + 7;
std::deque<int> dq;
int n, k, a[maxn], m[maxn], rem = 0, res = 0;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    // std::freopen(task".inp", "r", stdin);
    // std::freopen(task".out", "w", stdout);

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    while (dq.size())
        dq.pop_front();

    for (int i = 1; i <= n; i++)
    {
        while (dq.size() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (dq.front() + k <= i)
            dq.pop_front();

        // if (i >= k)
        m[i] = a[dq.front()];
    }

    for (int i = 1; i <= n; i++)
        res += m[i];

    std::cout << res;

    return 0;
}
