#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int solve(int n, const std::vector<int>& a) {
    std::unordered_map<int, int> m;
    m[0] = -1;
    int s = 0;
    int dex = -1;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        s += a[i];

        if (m.find(s) != m.end()) {
            if (m[s] >= dex) {
                ans++;
                dex = i;
            }
        }

        m[s] = i;
    }

    return ans;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<int> a(n + 7);
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::cout << solve(n, a) << "\n";
    }

    return 0;
}

