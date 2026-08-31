#include <bits/stdc++.h>
#define task "multisum"
#define ll long long
#define ld long double

ld a, tmp;
ll b, c;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> a >> b >> c;
    tmp = (ld) c / b;
    if (a > tmp) std::cout << 1;
    else         std::cout << 0;


    return 0;
}
