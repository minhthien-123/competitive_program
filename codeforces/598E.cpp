#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int N = 37;
const int M = 37;
const int K = 57;
const int inf = 1e18;

int t;
int dp[N][M][K];


long long dq(int w, int h, int d) {
    if (dp[w][h][d] != -1)    return dp[w][h][d];
    if (w * h < d)            return dp[w][h][d] = inf;
    if (d == 0 || w * h == d) return dp[w][h][d] = 0;

    dp[w][h][d] = inf;

    for (int q = 0; q <= d; q++) {
        for (int i = 1; i < w; i++) {
            dp[w][h][d] = std::min(dp[w][h][d],
            dq(i, h, q) + dq(w - i, h, d - q) + h);
        }
        for (int j = 1; j < h; j++) {
            dp[w][h][d] = std::min(dp[w][h][d],
            dq(w, j, q) + dq(w, h - j, d - q) + w);
        }
    }
    return dp[w][h][d];
}


signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    memset(dp, -1, sizeof dp);

    std::cin >> t;
    while (t--){
        int n, m, k;
        std::cin >> n >> m >> k;

        std::cout << dq(n, m, k) << "\n";
    }

    return 0;
}

