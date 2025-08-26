#include <bits/stdc++.h>
#define task "multiset"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int q;
std::multiset<int> mts;

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

    std::cin >> q;

    while (q--)
    {
        char c;
        int x;
        std::cin >> c >> x;
        if (c == '+')
        {
            mts.insert(x);
        }
        else if (c == '-')
        {
            auto it = mts.find(x);
            if (it != mts.end())
                mts.erase(it);
        }
        else
        {
            int res = 0;
            int l = 0, r = (1LL << 31) - 1;

            for (int i = 30; i >= 0; i--)
            {
                int bit = (x >> i) & 1;
                int check = bit ^ 1;

                int mask = (1LL << i) - 1;
                int u = (l & ~mask) | (check << i);
                int v = u + mask;

                u = std::max(u, l);
                v = std::min(v, r);

                auto it = mts.lower_bound(u);
                if (it != mts.end() && *it <= v)
                {
                    res |= (1LL << i);
                    l = u;
                    r = v;
                }
                else
                {
                    check = bit;
                    u = (l & ~mask) | (check << i);
                    v = u + mask;

                    u = std::max(u, l);
                    v = std::min(v, r);

                    l = u;
                    r = v;
                }
            }

            std::cout << res << "\n";
        }
    }

    return 0;
}