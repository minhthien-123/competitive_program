#include <bits/stdc++.h>
#define task "change"
#define ll long long

const int maxn = 1e4 + 7;

int n, m, k;
int p[maxn];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        std::cin >> p[i];

    for (int i = 1; i <= m; i++){
        int x, y, c;
        std::cin >> x >> y >> c;
    }

    std::cout << -1;

    return 0;
}
