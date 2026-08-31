#include <bits/stdc++.h>
#define ll long long

ll n, s;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("16cs.inp", "r", stdin);
    std::freopen("16cs.out", "w", stdout);

    std::cin >> n;
    s = 2009;
    if (n % 2 == 0)
        s = s - (n / 2);
    else{
        s = s - (n / 2);
        s += n;
    }

    std::cout << s;

    return 0;
}
