#include <bits/stdc++.h>
#define task "cover1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n;
ii a[maxn + 7];

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

    for (int i = 0; i < n; i++) {
        std::cin >> a[i].fi >> a[i].se;
    }

    std::sort(a, a + n);

    int ans = 0;
    int beg = a[0].fi;
    int en = a[0].se;

    for (int i = 1; i < n; i++) {
        if (a[i].fi <= en) {
            en = std::max(en, a[i].se);
        } else {
            ans += en - beg;
            beg = a[i].fi;
            en = a[i].se;
        }
    }

    ans += en - beg;

    std::cout << ans << std::endl;

    return 0;
}
