#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        std::cin >> x;
        a[x]++;
    }

    int ans = 0;
    for (int i = 1; i <= maxn; i++){
        ans += a[i] * (a[i] > 1);
    }

    std::cout << ans;

    return 0;
}

