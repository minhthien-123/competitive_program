#include <bits/stdc++.h>
#define task "folding"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

char get(int n, int k, bool flag){
    if (k == 1) return 'B';

    int mid = 1 << (n - 1);

    if (k == mid) return 'A';

    if (flag == true){
        if (k < mid)
            return get(n - 1, k, false);
        else
            return 'A' + 'B' - get(n - 1, 2 * mid - k, false);
    }else{
        if (k < mid)
            return 'A' + 'B' - get(n - 1, 2 * mid - k - mid, true);
        else
            return get(k - 1, k - mid, true);
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    int n, i, j;
    std::string res = "";
    std::cin >> n >> i >> j;

    for (int k = i; k <= j; k++)
        res += get(n, k, true);

    std::cout << res;

    return 0;
}

