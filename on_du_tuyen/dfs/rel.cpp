#include <bits/stdc++.h>
#define task "rel"
#define ll long long

int n, m;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++){
        int u, v;
        char c;
        std::cin >> u >> c >> v;
        std::cout << c << "\n";
    }

    return 0;
}
