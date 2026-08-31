#include <bits/stdc++.h>
#define task "strnext"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

std::string s;

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
    std::string s1 = s;

    int i = s.size() - 2;
    while (i >= 0 && s[i] >= s[i + 1])
    {
        i--;
    }

    if (i == -1)
    {
        std::sort(s.begin(), s.end());
    }
    else
    {
        int j = s.size() - 1;
        while (s[j] <= s[i])
        {
            j--;
        }

        std::swap(s[i], s[j]);
        std::reverse(s.begin() + i + 1, s.end());
    }

    if (s > s1)
    {
        std::cout << s;
    }
    else
    {
        std::cout << "NOTAVAILABLE";
    }

    return 0;
}
