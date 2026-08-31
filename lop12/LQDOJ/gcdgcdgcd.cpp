#include <bits/stdc++.h>
#define task "gcdgcdgcd"
#define ll long long

int gcd(int a, int b){
    while (b != 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int t;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> t;
    while (t--){
        int x, y;
        std::cin >> x >> y;
        int g = gcd(x, y);
        y -= g;
        //y = y / g * g;
        std::cout << g << " " << y << " ";
        std::cout << y / g<< "\n";
    }

    return 0;
}
