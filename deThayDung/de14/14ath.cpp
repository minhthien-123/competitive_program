#include <bits/stdc++.h>
#define ll long long

int n, a[1000005];
std::vector<std::pair<int, int>> v;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("14ath.inp", "r", stdin);
    std::freopen("14ath.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    for (int i = 1; i < n; i++)
        if (a[i] == a[i + 1])
            v.push_back(std::make_pair(i, i + 1));

    std::cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i].first << " " << v[i].second << "\n";

    return 0;
}
