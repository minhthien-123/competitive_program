#include <bits/stdc++.h>
#define task "lingvo"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n;
std::string a[10];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    for (int i = 0; i < 10; i++)
    {
        std::cin >> a[i];
    }

    std::cin >> n;

    while (n--)
    {
        std::string s;
        std::vector<std::string> ans;
        std::cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            ans.pb(a[s[i] - '0']);
        }

        std::sort(ans.begin(), ans.end());

        std::cout << ans[ans.size() - 1] << "\n";
    }

    return 0;
}
