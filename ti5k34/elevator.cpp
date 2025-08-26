#include <bits/stdc++.h>
#define task "train"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int n, m;
int a[maxn];

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
        std::cin >> a[i];
    }

    int ans = 0, i = 1;
    while (i <= n)
    {
        int sum = 0;
        while (sum + a[i] <= m)
        {
            sum += a[i];
            i++;
        }
        ans++;
    }

    std::cout << ans;

    return 0;
}