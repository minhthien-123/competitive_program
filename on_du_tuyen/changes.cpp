#include <bits/stdc++.h>
#define task "changes"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;
const int mod = 1000000007;
const int inv = (mod + 1) / 2;

std::string s, t;
int l[maxn + 7], r[maxn + 7];

void init()
{
    for (int i = 0; i <= 9; i++)
    {
        l[i + '0'] = i;
        r[i + '0'] = i;
    }

    l['a'] = 0;
    r['a'] = 3;
    l['b'] = 1;
    r['b'] = 4;
    l['c'] = 2;
    r['c'] = 5;
    l['d'] = 3;
    r['d'] = 6;
    l['e'] = 4;
    r['e'] = 7;
    l['f'] = 5;
    r['f'] = 8;
    l['g'] = 6;
    r['g'] = 9;
    l['?'] = 0;
    r['?'] = 9;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    init();

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    while (std::cin >> s >> t)
    {
        int m = s.size();

        s = " " + s;
        t = " " + t;

        int ans = 1;
        for (int i = 1; i <= m; i++)
        {
            int L = std::max(l[s[i]], l[t[i]]);
            int R = std::min(r[s[i]], r[t[i]]);
            int cnt = 0;
            if (L <= R)
            {
                cnt = (R - L + 1);
            }
            if (cnt == 0)
            {
                ans = 0;
                break;
            }
            ans = (ans * cnt) % mod;
        }
        std::cout << ans << "\n";
    }

    return 0;
}
