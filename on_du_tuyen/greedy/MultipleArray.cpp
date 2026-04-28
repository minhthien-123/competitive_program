#include <bits/stdc++.h>
#define task "MultipleArray"
#define int long long
#define fi first
#define se second

const int maxn = 1e5 + 7;

std::pair<int, int> a[maxn];
int n, ans = 0;


signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i].fi >> a[i].se;
    }

    int i = n;
    while (i >= 1){
        int x = a[i].fi, y = a[i].se;
        x += ans;
        x %= y;
        if (x == 0) x = y;
        ans += y - x;
        //std::cout << y - x << "\n";
        i--;
    }

    std::cout << ans;

    return 0;
}

// 5 6 2 3 6
