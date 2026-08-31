#include <bits/stdc++.h>

long long m, n, ans = 0, a[1000005], b[1000005];
std::map<long long, long long> a1, b1;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("dnum6.inp", "r", stdin);
    std::freopen("dnum6.out", "w", stdout);

    std::cin >> m >> n;
    for (long long i = 0; i < m; i++){
        std::cin >> a[i];
        a1[a[i]]++;
    }

    for (long long i = 0; i < n; i++){
        std::cin >> b[i];
        b1[b[i]]++;
    }

    for (long long i = 0; i < m; i++){
        if (a1[a[i]] < b1[a[i]]){
            ans += a1[a[i]];
            a1[a[i]] = 0;
        }else{
            ans += b1[a[i]];
            b1[a[i]] = 0;
        }
    }

    for (long long i = 0; i < n; i++){
        if (b1[b[i]] < a1[b[i]]){
            ans += b1[b[i]];
            b1[b[i]] = 0;
        }else{
            ans += a1[b[i]];
            a1[b[i]] = 0;
        }
    }

    std::cout << ans;

    return 0;
}