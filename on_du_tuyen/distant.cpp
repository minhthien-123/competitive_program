#include <bits/stdc++.h>
#define task "distant"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

int n, d, ans = 1, res = 0;
int a[maxn], dp[maxn], pre[maxn];
std::vector<int> path;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> d;
    
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    memset(dp, 1, sizeof dp);
    memset(pre, -1, sizeof pre);
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
            if (abs(a[i] - a[j]) >= d)
                if (dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                    pre[j] = i;
                }
        if (dp[i] > ans) {
            ans = dp[i];
            res = i;
        }
    }
    
    for (int i = res; i != -1; i = pre[i])
        path.pb(i);
    
    std::reverse(path.begin(), path.end());
    
    std::cout << ans << "\n";
    for (int i = 0; i < ans; ++i)
        std::cout << path[i] << " ";
    
    return 0;
}
