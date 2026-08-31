#include <bits/stdc++.h>
#define task "" 
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

bool isprime(int n){
    for(int i = 2; i <= sqrtl(n); i++)
        if(n % i == 0) 
            return false;
    return true;
}

bool cp(long double n){
    return sqrtl(n) == floorl(sqrtl(n)) && isprime(sqrtl(n));
}

int n, k;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    if (n == 1) std::cout << 4;
    else{
        while (!cp(n))
            n = ((int)sqrt(n) + 1) * ((int)sqrt(n) + 1);
        std::cout << n;
    }

    return 0;
}