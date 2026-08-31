#include <bits/stdc++.h>
#define task "remainder"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int calculate_remainder(int n, int m) {
    int r = 0, k = 1;
    
    for (int i = 1; i <= n; i++) {
        std::string s = std::to_string(i);
        
        int k = 1;
        for (int i = 0; i < s.size(); ++i)
            k = (k * 10) % m;
        
        r = (r * k + std::stoll(s)) % m;
    }
    
    return r;
}

signed main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    
    std::cout << calculate_remainder(n, m);
    
    return 0;
}
