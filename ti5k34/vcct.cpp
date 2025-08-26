#include <bits/stdc++.h>
#define task "vcct"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int n;
int a[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        int x;
        std::cin >> x;
        a[i] -= x;
    }

    std::sort(a + 1, a + n + 1, std::greater<int>());

    int s = 0;
    for (int i = 1; i <= n; i++){
        s += a[i];
        if (s < 0){
            std::cout << i - 1;
            return 0;
        }
    }

    std::cout << n;

    return 0;
}

