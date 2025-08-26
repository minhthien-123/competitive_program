#include <bits/stdc++.h>
#define task "eop"
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

std::string a;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> a;
    int n = a.size();
    a = " " + a;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i] - '0';
        for (int j = i + 1; j <= n; j++)
        {
            int y = a[j] - '0';
            if ((x - y) % 2 != 0)
            {
                cnt++;
            }
        }
    }

    std::cout << cnt;

    return 0;
}
