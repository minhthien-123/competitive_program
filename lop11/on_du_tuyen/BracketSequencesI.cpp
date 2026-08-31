#include <bits/stdc++.h>
#define task "BracketSequencesI"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int mod = 1e9 + 7;
const int maxn = 1e6 + 7;

int fact[maxn], inv[maxn];

int inverse(int x){
    int res = 1;
    int expo = mod - 2;
    while(expo > 0){
        if(expo & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        expo >>= 1;
    }
    return res;
}

void init(){
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= maxn; i++){
        fact[i] = i * fact[i - 1] % mod;
        inv[i] = inverse(fact[i]);
    }
}

int n;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;
    if (n % 2 != 0){
        std::cout << 0;
        return 0;
    }
    init();
    //std::cout << val(n, n / 2) - val(n, n / 2 - 1);

    int a = fact[n] * inv[n / 2] % mod * inv[n / 2] % mod;
    int b = fact[n] * inv[n / 2 + 1] % mod * inv[n / 2 - 1] % mod;

    std::cout << (a +) - b;

    return 0;
}
