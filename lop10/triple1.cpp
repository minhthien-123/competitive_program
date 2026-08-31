#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::set<int> unique_elements(a.begin(), a.end());
    std::vector<int> distinct_elements(unique_elements.begin(), unique_elements.end());

    n = distinct_elements.size();
    std::tuple<int, int, int> res = std::make_tuple(LLONG_MAX, LLONG_MAX, LLONG_MAX);
    bool flag = false;

    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            int ai = distinct_elements[j];
            int aj = distinct_elements[k];
            int ak = 2 * aj - ai;

            if (unique_elements.find(ak) != unique_elements.end()) {
                flag = true;
                auto tmp = std::make_tuple(ai, aj, ak);
                if (tmp < res) {
                    res = tmp;
                }
            }
        }
    }

    if (flag) {
        std::cout << std::get<0>(res) << " " << std::get<1>(res) << " " << std::get<2>(res) << std::endl;
    } else {
        std::cout << "0 0 0" << std::endl;
    }

    return 0;
}
