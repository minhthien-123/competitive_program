#include <bits/stdc++.h>
#define task "mularr"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

ll solve(const std::vector<int>& a) {
    int n = a.size();
    
    ll s = std::accumulate(a.begin(), a.end(), 0LL);
    
    ll ss = 0;
    for (int i : a)
        ss += static_cast<ll>(i) * i;
    
    ll result = (s * s - ss) / 2;
    
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cout << solve(a);

    return 0;
}
