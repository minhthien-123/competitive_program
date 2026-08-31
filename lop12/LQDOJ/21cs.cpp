#include <bits/stdc++.h>
#define task "21cs"
#define ll long long

const ll mod = 1e9 + 7;
inline ll sqr(ll x){return (x * x) % mod;}
ll n, m;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    if (n % 2 == 0){
        m = n / 2;
        std::cout << (sqr(m) * sqr(n + 1)) % mod;
    }
    else{
        m = (n + 1) / 2;
        std::cout << (sqr(m) * sqr(n)) % mod;
    }

    return 0;
}
