#include <bits/stdc++.h>
#define task "vending"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n;
std::vector<int> a;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1, x; i <= n; i++){
        std::cin >> x;
        a.pb(x);
    }

    int ans = 1;

    for (int i : a){
        if (i > ans)
            break;
        ans += i;
    }

    std::cout << ans;

    return 0;
}

