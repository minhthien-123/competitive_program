#include <bits/stdc++.h>
#define task "mbth"
#define int long long
#define ull unsigned long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n;
ull m;
std::pair<ull, ull> a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
    }

    std::sort(a + 1, a + n + 1);

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << a[i].fi << " " << a[i].se << "\n";
    }*/

    ull sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ull tmp = m - sum;
        if (a[i].fi * a[i].se <= tmp)
        {
            sum += a[i].fi * a[i].se;
            ans += a[i].se;
        }
        else
        {
            ans += tmp / a[i].fi;
            break;
        }
    }

    std::cout << ans;

    return 0;
}
