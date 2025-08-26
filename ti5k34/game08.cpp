#include <bits/stdc++.h>
#define task "game08"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n, m;
    std::cin >> n >> m;
    int a[n + 7], b[m + 7];
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        std::cin >> b[i];
    }
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + m + 1);

    int i = 1, j = m, res = abs(a[i] + b[j]);
    while (i < n || j > 1){
        if (i == n){
            j--;
        }
        else if (j == 1){
            i++;
        }else if (abs(a[i] + b[j]) < abs(a[i] + b[j - 1])){
            i++;
        }else{
            j--;
        }

        res = std::min(res, abs(a[i] + b[j]));
    }

    std::cout << res;

    return 0;
}

