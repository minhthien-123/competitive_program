#include <bits/stdc++.h>
using namespace std;
#define task "garbot"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

bool check(std::vector<int> a, std::vector<int> b, ll x) {
    int n = b.size();
    int m = a.size();
    std::vector<bool> flag(n, false);
    int j = 0;

    for (int i = 0; i < m; i++) {
        int start = max(a[i] - x, 0LL);
        int end = a[i] + x;

        while (j < n && b[j] < start) {
            j++;
        }


        while (j < n && b[j] <= end) {
            flag[j] = true;
            j++;
        }
    }

    for (bool c : flag) {
        if (!c) return false;
    }

    return true;
}

ll solve(std::vector<int> a, std::vector<int> b) {
    ll l = 0, r = 2e9;
    ll result = r;

    while (l <= r) {
        ll mid = l + (r - l) / 2;

        if (check(a, b, mid)) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return result;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int m, n;
    std::cin >> m >> n;

    std::vector<int> a(m);
    std::vector<int> b(n);

    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::cout << solve(a, b);

    return 0;
}