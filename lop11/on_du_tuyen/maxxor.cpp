#include <bits/stdc++.h>
#define task "maxxor"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7];

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

    int res = 0;
    int mask = 0;

    for (int i = 32; i >= 0; i--)
    {
        mask |= (1LL << i);
        int tmp = res | (1LL << i);

        std::unordered_set<int> s;

        for (int j = 1; j <= n; j++)
        {
            s.insert(a[j] & mask);
        }

        for (int j : s)
        {
            if (s.count(j ^ tmp))
            {
                res = tmp;
                break;
            }
        }
    }

    std::cout << res;

    return 0;
}
