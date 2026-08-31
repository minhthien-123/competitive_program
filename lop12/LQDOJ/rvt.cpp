#include <bits/stdc++.h>
//#define task "rvt"
#define ll long long
#define ld long double

ll t;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> t;
    while (t--){
        ll a, b, c, d, t1, t2;
        std::cin >> a >> b >> c >> d >> t1 >> t2;
        ll s1 = b - a, s2 = d - c;
        ld v1 = s1 / t1, v2 = s2 / t2;

        if (v1 > v2)
            std::cout << "Rua\n";
        else if (v1 < v2)
            std::cout << "Tho\n";
        else
            std::cout << "Cun\n";

    }

    return 0;
}
