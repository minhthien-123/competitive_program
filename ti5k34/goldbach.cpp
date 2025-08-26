#include <bits/stdc++.h>
#define task "goldbach"
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

int n;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = n / 2; i >= 2; i++)
        if (isprime(i) && isprime(n - i)){
            std::cout << std::min(i, n - i) << " " << std::max(i, n - i);
            return 0;
        }

    return 0;
}