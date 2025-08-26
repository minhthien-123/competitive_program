#include <bits/stdc++.h>
#define task "mmedian"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, k;
int a[maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::multiset<int> s;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        s.ins(a[i]);

        if (i >= k - 1)
        {
            auto it = s.begin();
            advance(it, (s.size() - 1) / 2);
            int tmp = *it;
            ans = std::max(ans, tmp);

            s.erase(s.find(a[i - k + 1]));
        }
    }

    std::cout << ans;

    return 0;
}
