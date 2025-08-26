#include <bits/stdc++.h>
#define task "landval"
#define ll long long

const int maxn = 1e3 + 7;

int n, m, k;
ll t[maxn][maxn], a[maxn][maxn], ans = LLONG_MIN;
std::deque<int> dq;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen(task ".inp", "r", stdin);
    std::freopen(task ".out", "w", stdout);

    std::cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        while (dq.size())
            dq.pop_front();
        for (int j = 1; j <= m; j++)
        {
            while (dq.size() && a[i][dq.back()] >= a[i][j])
                dq.pop_back();
            dq.push_back(j);
            if (dq.front() + k <= j)
                dq.pop_front();

            if (j >= k)
                t[i][j] = a[i][dq.front()];
        }
    }

    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++)
        {
            ll res = LLONG_MAX;
            for (int p = i - k + 1; p <= i; p++)
                res = std::min(res, t[p][j]);
            ans = std::max(ans, res);
        }

    std::cout << ans;

    return 0;
}
