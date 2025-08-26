#include <bits/stdc++.h>
#define task
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int lcm(int a, int b){
    return a / std::__gcd(a, b) * b;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << lcm(abs(a), (lcm(abs(b), abs(c))));

    return 0;
}

