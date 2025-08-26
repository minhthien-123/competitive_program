#include <bits/stdc++.h>
#define task "bistr"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 20230928;
const int inv  = (mod + 1) / 2;

int n;
std::string s;

void sub1()
{
    int ans = 0;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        std::string t;
        for (int i = n - 1; i >= 0; i--)
        {
            if (mask & (1 << i))
            {
                t.pb('1');
            }
            else
            {
                t.pb('0');
            }
        }

        if (t.find(s) == std::string::npos)
        {
            ans++;
        }

        ans %= mod;
    }

    std::cout << ans;
}

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
    std::cin >> s;

    sub1();

    return 0;
}