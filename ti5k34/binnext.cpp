#include <bits/stdc++.h>
#define task "binnext"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;

std::string s;
bool check = true;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> s;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            check = false;
            s[i] = '1';
            for (int j = i + 1; j < s.size(); j++)
            {
                s[j] = '0';
            }
            break;
        }
    }

    if (check)
    {
        std::cout << "NOTAVAILABLE";
        return 0;
    }

    for (int i = 0; i < s.size(); i++)
    {
        std::cout << s[i];
    }

    return 0;
}
