#include <bits/stdc++.h>
#define task "bonus"
#define ll long long

const int maxn = 1e3 + 7;
const int maxk = 1e6 + 7;

int n, r, k;
ll a[maxn][maxn], pre[maxn][maxn], ans = 0, f[maxn][maxn];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> r >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> a[i][j];

    while (k --){
        int x, y;
        std::cin >> x >> y;

        f[x][y] ++;
        f[x][y + r] --;
        f[x + r][y] --;
        f[x + r][y + r] ++;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + f[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (pre[i][j] != 0)
                ans += a[i][j];

    std::cout << ans;
    return 0;
}
