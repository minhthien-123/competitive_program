#include <bits/stdc++.h>
#define task "seqk"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int a[maxn];
std::map<int, int> m;

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (m[a[i] - k] != 0) {
            std::cout << i << " " << m[a[i] - k];
            return 0;
        }
        if (m[a[i] + k] != 0) {
            std::cout << m[a[i] + k] << " " << i;
            return 0;
        }
        m[a[i]] = i;
    }
    std::cout << "0 0";
    return 0;
}
