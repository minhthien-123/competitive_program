#include <bits/stdc++.h>
#define task "pairs"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf  = 1e18;

int n, k, cnt = 0;
std::string a[maxn + 7];
std::unordered_map<int, int> mp;

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (i > k)
        {
            mp[a[i - k - 1].size()]--;
        }

        cnt += mp[a[i].size()];
        mp[a[i].size()]++;
    }

    std::cout << cnt;

    return 0;
}
