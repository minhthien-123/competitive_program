#include <bits/stdc++.h>
#define task "wood"
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
int a[maxn + 7];
std::vector<int> res;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    int ans = -inf;
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = i;
        while (l > 1 && a[l - 1] % a[i] == 0)
        {
            l--;
        }
        while (r < n && a[r + 1] % a[i] == 0)
        {
            r++;
        }

        int tmp = r - l;
        if (tmp > ans)
        {
            ans = tmp;
            res.clear();
            res.pb(l);
        }
        else if (tmp == ans)
        {
            res.pb(l);
        }
    }

    std::sort(res.begin(), res.end());
    auto last = std::unique(res.begin(), res.end());
    res.erase(last, res.end());

    for (int i : res)
    {
        std::cout << i << " ";
    }

    return 0;
}
