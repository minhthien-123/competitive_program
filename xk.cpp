#include <bits/stdc++.h>
#define task "xk"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

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

    int Q;
    std::cin >> Q;
    while (Q--)
    {
        std::string s;
        std::cin >> s;
        bool check = true;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[0])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << "YES\n";
        }
    }

    return 0;
}
