#include <bits/stdc++.h>
#define task "maxnum"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5 + 7;

bool compare(std::string x, std::string y) {
    return x + y > y + x;
}

int n;
std::string a[maxn];

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;

    for (int i = 1, x; i <= n; i++)
        std::cin >> a[i];

    std::sort(a + 1, a + n + 1, compare);

    std::string result;
    for (int i = 1; i <= n; i++)
        result += a[i];

    std::cout << result;

    return 0;
}
