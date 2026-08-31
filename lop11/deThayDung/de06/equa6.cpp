#include <bits/stdc++.h>

long double a1, b1, c1, a2, b2, c2, d, dx, dy, x, y;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("equa6.inp", "r", stdin);
    std::freopen("equa6.out", "w", stdout);

    std::cin >> a1 >> b1 >> c1;
    std::cin >> a2 >> b2 >> c2;

    if (a1 == b1 && a1 == 0 && c1 != 0){
        std::cout << "NO SOLUTION";
        return 0;
    }

    if (a2 == b2 && a2 == 0 && c2 != 0){
        std::cout << "NO SOLUTION";
        return 0;
    }

    d = a1 * b2 - a2 * b1;
    dx = c1 * b2 - c2 * b1;
    dy = a1 * c2 - a2 * c1;

    //std::cout << d << " " << dx << " " << dy << std::endl;

    if (d == 0)
        if (dx == 0 && dy == 0)
            std::cout << "INFINITE";
        else
            std::cout << "NO SOLUTION";
    else{
        x = dx / d;
        y = dy / d;
        if (x == 0)
            std::cout << "0.00 ";
        else
            std::cout << std::setprecision(2) << std::fixed << x << " ";
        if (y == 0)
            std::cout << "0.00";
        else
            std::cout << std::setprecision(2) << std::fixed << y;

        //std::cout << "\n" << std::setprecision(2) << std::fixed << x << " " << y;
    }

    return 0;
}