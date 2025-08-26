#include <bits/stdc++.h>
#define task "quartet"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, ans = 0;
int a[maxn], d[maxn], dp[maxn][100], f[100][100];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }

    for (int i = 1 ; i <= 100 ; i++){
        for (int j = n ; j >= 1 ; j--)
             dp[j][i] = dp[j + 1][i] + (a[j] == i);
    }

    for (int j = 1 ; j <= n ; j++){
        for (int i = 1 ; i <= 100 ; i++){
            ans += f[i][a[j]] * dp[j + 1][i];
            f[i][a[j]] += d[i];
        }
        d[a[j]]++;
    }

    std::cout << ans;

    return 0;
}

/*
7
2 1 2 1 2 1 1

x < y < z < w
ax = aw
ay = az
*/
