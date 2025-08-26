#include <bits/stdc++.h>
#define task
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int mod = 123456789;
const int maxn = 1e5 + 7;

int n, x, res = 0;
int a[maxn];

int power(int x, int n){
    if (n == 0){
        return 1;
    }

    int tmp = power(x, n / 2);
    if (n % 2 == 0){
        return (tmp * tmp) % mod;
    }else{
        return ((tmp * tmp) % mod * x) % mod;
    }
}

int mul(int n) {
  return power(n, mod - 2);
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n >> x;

    for (int i = 0; i <= n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i <= n; ++i) {
        int tmp = a[i];
        int pw = power(abs(x), i);
        if (x < 0 && i % 2 != 0) {
            pw = (mod - pw) % mod;
        }

        tmp = (tmp * pw) % mod;
        res = (res + tmp + mod) % mod;
    }

    std::cout << res;
    return 0;
}
