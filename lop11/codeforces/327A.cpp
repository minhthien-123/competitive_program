#include <bits/stdc++.h>
#define task "codeforces"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int n, d = 0, s = 0, ans = 0, a[maxn];

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
        if (a[i] == 1){
            d++;
        }
    }

    for (int i = 1; i <= n; i++){
        if (a[i] == 0){
            s++;
        }else{
            s--;
        }

        ans = std::max(ans, s);
        if (s < 0){
            s = 0;
        }
    }

    if (d == n){
        std::cout << n - 1;
    }else{
        std::cout << d + ans;
    }

    return 0;
}

