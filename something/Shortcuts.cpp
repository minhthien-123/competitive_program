#include <bits/stdc++.h>
#define ll long long

const double inf = 1e9;
std::vector<std::vector<int>> f;
double dp[10007][29][29];
int n;

inline double sqr(double x){return x * x;}

double dist(int x, int y){
    double dist1 = f[x][0] - f[y][0];
    double dist2 = f[x][1] - f[y][1];
    return sqrt(sqr(dist1) + sqr(dist2));
}

double solve(int i, int skip, int lskip){
    int l = i - lskip - 1;
    if (skip > 27)
        return inf;

    if (i == n - 1){
        if (skip == 0) return dist(l, n - 1);
        return dist(l, n - 1) + (1 << (skip - 1));
    }

    if (dp[i][skip][lskip] >= 0) return dp[i][skip][lskip];

    return dp[i][skip][lskip] = std::min(dist(l, i) + solve(i + 1, skip, 0), solve(i + 1, skip + 1, lskip + 1));
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 29; j++)
            for (int k = 0; k < 29; k++)
                dp[i][j][k] = -1.0;

    f = std::vector<std::vector<int>>(n + 7, std::vector<int>(2));
    for (int i = 0; i < n; i++)
        std::cin >> f[i][0] >> f[i][1];

    std::cout << std::setprecision(16) << std::fixed << solve(1, 0, 0);

    return 0;
}
