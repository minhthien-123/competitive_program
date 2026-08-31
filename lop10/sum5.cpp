#include <bits/stdc++.h>
#define task "sum5"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;

    if (n % 5 != 0)
    {
        std::cout << -1;
    }
    else
    {
        n /= 5;
        std::cout << n - 2 << " " << n - 1 << " " << n << " " << n + 1 << " " << n + 2;
    }

    return 0;
}