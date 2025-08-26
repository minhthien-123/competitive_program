#include <bits/stdc++.h>
#define task "smin"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
int a[maxn], n;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1, x; i <= n; i++){
        std::cin >> x;
        if (x <= maxn){
            a[x]++;
            //std::cout << x << "\n";
        }
    }

    int i = 1;
    while(a[i] != 0){
        i++;
    }

    std::cout << i;

    return 0;
}

