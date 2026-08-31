#include <bits/stdc++.h>
#define task "intsle"
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

    int n;
    std::cin >> n;
    while (n--){
        int a1, a2, b1, b2, c1, c2;
        std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        int d  = a1 * b2 - a2 * b1;
        int dx = b2 * c1 - b1 * c2;
        int dy = a1 * c2 - a2 * c1;

        //std::cout << d << " " << dx << " " << dy << " ";

        if (a1 == b1 && a1 != 0 && c1 % a1 != 0) std::cout << "NO SOLUTION";
        else if (a2 == b2 && a2 != 0 && c2 % a2 != 0) std::cout << "NO SOLUTION";
        else if (a1 == b1 && a1 == 0 && c1 != 0) std::cout << "NO SOLUTION";
        else if (a2 == b2 && a2 == 0 && c2 != 0) std::cout << "NO SOLUTION";

        else if (d != 0){
            if (dx % d != 0 || dy % d != 0){
                std::cout << "NO SOLUTION";
            }else{
                std::cout << dx / d << " " << dy / d;
            }
        }else{
            if (dx != 0 || dy != 0) std::cout << "NO SOLUTION";
            if (dx == dy && dx == 0) std::cout << "INFINITE";
        }

        std::cout << "\n";
    }

    return 0;
}

