#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int m;
    std::cin >> m;
    std::vector<std::vector<int>> v(m + 9);
    for (int i = 0; i <= m + 1; i++){
        v[i].resize(i + 1);
        v[i][0] = v[i][i] + 1;

        for (int j = 1; j < i; j++)
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
    }

    for (int i = 1; i <= m + 1; i++){
        for (int j = 0; j < i; j++)
            std::cout << v[i][j] << " ";
        std::cout << "\n";
    }

    return 0;
}

