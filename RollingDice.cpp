#include <bits/stdc++.h>

int a, b;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> a >> b;
    if (6 * a >= b && b >= a) std::cout << "Yes";
    else                      std::cout << "No";

    return 0;
}
