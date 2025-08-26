#include <bits/stdc++.h>
#define task "csdk"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int n, k, ans = 0;
int a[maxn], d[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] %= k;
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        a[i] %= k;
        d[a[i]]++;
    }

    /*for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";*/

    ans = d[0];
    for (int i = 1; i <= n; i++)
    {
        d[a[i]]--;
        if (d[a[i]] > 0)
        {
            ans += d[a[i]];
        }
    }

    std::cout << ans;

    return 0;
}


// 3 3
// 1 3 6

// 1 1 1
//