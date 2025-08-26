#include <bits/stdc++.h>
#define ll long long

struct arr{
    ll val, dex;
};

bool ss(arr x, arr y){
    if (x.val < y.val) return true;
    return false;
}

arr w[1000005], b[1000005];
ll n, i, j, d, ans = 0, k;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("14poi.inp", "r", stdin);
    std::freopen("14poi.out", "w", stdout);

    std::cin >> n;

    i = 0; j = 0;
    for (k = 0; k < 2 * n; k++){
        char s;
        ll x;
        std::cin >> s >> x;
        if (s == 'W'){
            w[i].val = x;
            w[i].dex = k;
            i++;
        }else{
            b[j].val = x;
            b[j].dex = k;
            j++;
        }
    }

    std::sort(w, w + n, ss);
    std::sort(b, b + n, ss);

    for (i = 0; i < n; i++) ans += abs(w[i].val - b[i].val);

    std::cout << ans;

    return 0;
}
