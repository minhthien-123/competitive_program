#include <bits/stdc++.h>
#define task "beautarr"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e5;
const int inf  = 1e18;

int n;
int a[maxn + 7], d[maxn + 7];

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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        d[a[i]] = 0;
    }

    int cnt = 0;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        d[a[i]]++;
        while (d[a[i]] > 2)
        {
            d[a[j]]--;
            j++;
        }
        cnt += i - j + 1;
    }

    std::cout << cnt << "\n";

    return 0;
}
