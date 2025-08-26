#include <bits/stdc++.h>
#define task "stones"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e4 + 7;
const int maxk = 107;

int n, k, a[maxk], dp[maxn], ans;
bool flag = true;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> k;
    for (int i = 1; i <= k; i++)
        std::cin >> a[i];

    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            if (i >= a[j])
                dp[i] = std::max(dp[i], i - dp[i - a[j]]);

    //for (int i = 1; i <= n; i++)
        //std::cout << dp[i] << " ";
    //std::cout << "\n";

    std::cout << dp[n];

    return 0;
}
