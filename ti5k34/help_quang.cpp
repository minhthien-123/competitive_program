#include <bits/stdc++.h>
#define task "help_quang"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;

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
    std::set<int> s;
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        if (s.lower_bound(x) == s.begin())
        {
            std::cout << -1;
        }
        else
        {
            std::cout << *(--s.lower_bound(x));
        }
        s.ins(x);
        std::cout << "\n";
    }

    return 0;
}
