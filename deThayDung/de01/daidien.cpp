#include <bits/stdc++.h>
#define ll long long

std::unordered_map<ll, ll> res;
ll sum, ans, en, a[1000005], n, maxlen;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("daidien.inp", "r", stdin);
    std::freopen("daidien.out", "w", stdout);

    std::cin >> n;
    for (ll i = 0, x; i < n; i++){
        std::cin >> x;
        if (x < 0) a[i] = -1;
        else if (x == 0) a[i] = 0;
        else a[i] = 1;
    }

    //for (ll i = 0; i < n; i++) std::cout << a[i] << ' ';
    //std::cout << "\n";

    for (ll i = 1; i < n; i++) a[i] += a[i - 1];

    //for (ll i = 0; i < n; i++) std::cout << a[i] << ' ';
    //std::cout << "\n";

    sum = 0;
    ans = 0;
    en = 0;

    for (ll i = 0; i < n; i++){
        if (a[i] == 0){
            maxlen = i;
            en = i;
        }else{
            if(res[a[i]] == 0)
                res[a[i]] = i;
            else{
                if ((i - res[a[i]]) > maxlen){
                    maxlen = i - res[a[i]];
                    en = i;
                }
            }
        }
    }

    if (maxlen == 0){
        std::cout << 0;
        return 0;
    }

    std::cout << en - maxlen + 2 << " " << en + 1;

    return 0;
}