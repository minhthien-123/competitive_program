#include <bits/stdc++.h>
#define task ""
#define int unsigned long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int find_bit(unsigne long long n) {
    int bit = 0;
    while (n > 0) {
        if (n % 2 == 1)
            bit = 1 - bit;
        n /= 2;
    }
    return bit;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int t;
    std::cin >> t;

    while(t--){
        int n;
        std::cin >> n;
        std::cout << find_bit(n) << "\n";
    }

    return 0;
}
