#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define task "thungan"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define ins insert

#define ordered_set tree<ii, null_type, std::less<ii>, rb_tree_tag, tree_order_statistics_node_update>

int n, x;
ordered_set s;
int cnt = 0;

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

    std::cin >> n >> x;
    int add = 0;
    int id = 0;

    while (n--)
    {
        char type;
        int k;
        std::cin >> type >> k;
        if (type == 'I')
        {
            if (k >= x)
            {
                s.ins({k - add, id++});
            }
            else
            {
                cnt++;
            }
        }
        else if (type == 'A')
        {
            add += k;
        }
        else if (type == 'S')
        {
            add -= k;

            while (!s.empty())
            {
                auto it = s.begin();
                if (it->fi < x - add)
                {
                    s.erase(*it);
                    cnt++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (k <= 0 || k > (int)s.size())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                auto it = s.find_by_order((int)s.size() - (int)k);
                int res = it->fi + add;
                std::cout << res << '\n';
            }
        }
    }
    std::cout << cnt << '\n';

    return 0;
}
