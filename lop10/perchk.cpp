#include <bits/stdc++.h>
#define task "perchk"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;

int n, a[maxn];
bool flag = true;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        std::cin >> x;
        if (x > n) flag = false;
        else if (x < 0) flag = false;
        else if (a[x] == 1) flag = false;
        if (x <= n) a[x]++;
    }

    if (flag) std::cout << "YES";
    else      std::cout << "NO";

    return 0;
}

