#include <bits/stdc++.h>
#define task "shh"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    int a, ans = 0;
    std::cin >> a;
    a = a * a;

    bool cmp = (a % 2 != 0);

    a /= 2;


    //std::cout << a << "\n";

    while (a > 0){
        //std::cout << a % 10 << "\n";
        ans += a % 10;
        a /= 10;
    }

    ans += cmp * 5;

    std::cout << ans;

    return 0;
}

