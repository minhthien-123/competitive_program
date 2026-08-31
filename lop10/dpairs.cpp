#include <bits/stdc++.h>
#define task "dpairs"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
const int tt = 1e3 + 7;

int n, k, ans = 0;
int a[maxn];
std::map<int, int> d;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")) {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        d[a[i]]++;
    }

    for (int i = 1; i <= n; i++){
        d[a[i]]--;
        ans += d[a[i] + k];
        ans += d[a[i] - k];
    }

    //if (k == 0) ans /= 2;

    std::cout << ans;

    return 0;
}
