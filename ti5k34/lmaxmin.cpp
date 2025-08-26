#include <bits/stdc++.h>
#define task "lmaxmin"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;

int n, k;
int a[maxn + 7];
std::deque<int> mx, mn;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int ans = 0, l = 0;
    for (int r = 0; r < n; r++)
    {
        while (!mx.empty() && a[r] >= a[mx.back()])
        {
            mx.pop_back();
        }
        mx.push_back(r);

        while (!mn.empty() && a[r] <= a[mn.back()])
        {
            mn.pop_back();
        }
        mn.push_back(r);

        while (!mx.empty() && mx.front() < l)
        {
            mx.pop_front();
        }
        while (!mn.empty() && mn.front() < l)
        {
            mn.pop_front();
        }

        while (true)
        {
            if (mx.empty() || mn.empty())
                break;
            int current_max = a[mx.front()];
            int current_min = a[mn.front()];
            if (current_max - current_min <= k)
                break;
            l++;
            while (!mx.empty() && mx.front() < l)
            {
                mx.pop_front();
            }
            while (!mn.empty() && mn.front() < l)
            {
                mn.pop_front();
            }
        }

        if (!mx.empty() && !mn.empty())
        {
            ans = std::max(ans, r - l + 1);
        }
    }

    std::cout << ans;

    return 0;
}
