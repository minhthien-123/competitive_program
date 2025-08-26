#include <bits/stdc++.h>
#define ll long long

ll a[1000005], n, sum, ans, en, len, maxlen;
std::map<ll, ll> res;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    //std::freopen("szero.inp", "r", stdin);
    //std::freopen("szero.out", "w", stdout);

    std::cin >> n;
    a[0] = 0;
    for (ll i = 1; i <= n; i++){
        std::cin >> a[i];
        a[i] += a[i - 1];
    }

    /*for (ll i = 1; i <= n; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";*/

    for (ll i = 1; i <= n; i++){
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

    /*for (ll i = 1; i <= 30; i++)
        std::cout << i << " ";
    std::cout << "\n";

    for (ll i = 1; i <= 30; i++)
        std::cout << res[i] << " ";
    std::cout << "\n";*/

    if (maxlen == 0){
        std::cout << 0;
        return 0;
    }

    std::cout << en - maxlen + 1 << " " << en;

    return 0;
}