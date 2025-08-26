#include <bits/stdc++.h>
#define task "xaucon"
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

int k;
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

    std::cin >> k >> s;
    int n = s.size();

    if (k == 0)
    {
        int ans = 0;
        int len = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                len++;
            }
            else
            {
                ans += len * (len + 1) / 2;
                len = 0;
            }
        }
        ans += len * (len + 1) / 2;
        std::cout << ans;
        exit(0);
    }

    std::vector<int> pos;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            pos.pb(i);
        }
    }

    int ans = 0;
    for (int i = 0; i + k - 1 < pos.size(); i++)
    {
        int l = pos[i];
        int r = pos[i + k - 1];
        int bl, ar;
        if (i - 1 >= 0)
        {
            l = l - pos[i - 1];
        }
        else
        {
            l = l + 1;
        }

        if (i + k < pos.size())
        {
            r = pos[i + k] - r;
        }
        else
        {
            r = n - r;
        }

        ans += l * r;
    }

    std::cout << ans;

    return 0;
}
