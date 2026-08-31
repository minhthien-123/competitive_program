#include <bits/stdc++.h>
#define task "delvals"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int n, m, a[maxn], d[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }

    for (int i = 1, x; i <= m; i++){
        std::cin >> x;
        d[x]++;
    }

    for (int i = 1; i <= n; i++){
        if (d[a[i]] <= 0){
            std::cout << a[i] << " ";
        }
        d[a[i]]--;
    }

    return 0;
}
