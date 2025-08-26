#include <bits/stdc++.h>
#define task "delnum"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int n, m, ans;
std::map<int, int> a, b;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x;
        std::cin >> x;
        a[x]++;
    }

    for (int i = 1; i <= m; i++){
        int x;
        std::cin >> x;
        b[x]++;
    }

    std::cout << ans;

    return 0;
}
/*if (a == 0){
    if (b == 0)
        std::cout << "vsn";
    else
        std::cout << "vn";
}else{
    if (b % a != 0)
        std::cout << "vn";
    else
        std::cout << b / a;
}*/
