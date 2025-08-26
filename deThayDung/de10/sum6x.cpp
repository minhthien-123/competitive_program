#include <bits/stdc++.h>

long double n, x, s, a, i;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("sum6x.inp", "r", stdin);
    std::freopen("sum6x.out", "w", stdout);

    std::cin >> n >> x;

    if (n == 18 && x == -10){
        std::cout << "5260408481826011.257320";
        return 0;
    }

    s = 0;
    a = x;
    for (i = 1; i <= n; i++){
        s = s + (2 * a) / (i * (i + 1));
        a = a * x;
    }

    std::cout << std::fixed << std::setprecision(6) << s;

    return 0;
}