#include <bits/stdc++.h>

long double a, b, c, del;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("quae24.inp", "r", stdin);
    std::freopen("quae24.out", "w", stdout);

    std::cin >> a >> b >> c;
    del = b * b - 4 * a * c;

    if (b == c && c == 0)
        std::cout << "0.0000";
    else if (c == 0){
        if (b / a > 0){
            std::cout << std::setprecision(4) << std::fixed << -b / a << "\n";
            std::cout << "0.0000";
        }else if (b / a < 0){
            std::cout << "0.0000\n";
            std::cout << std::setprecision(4) << std::fixed << -b / a;
        }
    }
    else if (del < 0)
        std::cout << "NO SOLUTION";
    else if(del == 0)
        std::cout << std::setprecision(4) << std::fixed << (-b / (2 * a));
    else{
        long double x = ((-b - sqrt(del)) / (2 * a)), y = ((-b + sqrt(del)) / (2 * a));
        std::cout << std::setprecision(4) << std::fixed << std::min(x, y) << "\n" << std::max(x, y);
    }
    return 0;
}