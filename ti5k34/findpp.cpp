#include <bits/stdc++.h>
#define task "findpp"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;
std::vector<bool> f(maxn, true);
std::vector<int> cnt(maxn, 0);
std::vector<int> p;
std::vector<int> cd;

int min_prime[maxn];
void sieve(int n){
    for (int i = 2; i * i <= n; i++) {
        if (min_prime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
        }
    }
}

std::vector<int> fact(int n){
    std::vector<int> res;
    for (int i = 2; i <= n; i++){
        while (n % i == 0){
            res.pb(i);
            n /= i;
        }
    }
    if (n > 1) res.pb(n);
    return res;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    sieve(maxn);

    int t;
    std::cin >> t;
    while (t--){
        int n, maxx = -maxn;
        std::cin >> n;
        //std::vector<ii> v;

        for (int i = 1; i <= n; i++){
            int x;
            std::cin >> x;
            std::vector<int> res = fact(x);
            std::vector<ii> v;

            int j = 0;
            int d = 1;
            while (j < res.size()){
                while (res[j] == res[j + 1] && j < res.size()){
                    d++;
                    j++;
                }
                v.pb({res[j], d});
                d = 1;
                j++;
            }

            std::cout << x << "\n";
            for (auto j : v)
                std::cout << j.fi << " " << j.se << "\n";
            std::cout << "\n";

            maxx = std::max(maxx, x);
        }

        while (min_prime[maxx] != maxx) maxx++;
    }

    return 0;
}

// 1 2 3 4   5 6    7 8     9
// 1 2 3 2 2 5 2 3  7 2 2 2 3 3

// 2 3 5 7 11 12
// 2 3 5 7 11 2 2 3
//
