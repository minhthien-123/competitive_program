#include <bits/stdc++.h>
#define ll long long

ll t[39], q, a, b, tmp;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    tmp = 2;
    t[0] = 1;
    for (ll i = 1; i <= 29; i++){
        t[i] = tmp;
        tmp *= 2;
    }

    for (ll i = 0; i <= 29; i++) std::cout << t[i] << " ";

    std::cin >> q;

    while (q--){
        std::cin >> a >> b;

    }

    return 0;
}

MIN