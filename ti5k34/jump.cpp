#include <bits/stdc++.h>
#define task "jump"
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

    std::sort(a + 1, a + n + 1);

    int i = 1, j = n, ans = 0;

    while (i <= j)
    {
        if (a[j] + a[i] <= m)
        {
            ans++;
            j--;
            i++;
        }
        else
        {
            ans++;
            j--;
        }
    }

    std::cout << ans;

    return 0;
}