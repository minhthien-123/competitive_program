#include <bits/stdc++.h>
#define ll long long

ll maxn = 1e6;
ll n, a[1000005], ans = 0;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("pers12.inp", "r", stdin);
    std::freopen("pers12.out", "w", stdout);

    for (int i = 1; i <= maxn; i++)
        for (int j = i; j <= maxn; j += i)
            a[j] += i;

    std::cin >> n;
    while (n--){
        long long x;
        std::cin >> x;
        if (a[x] - x == x)
            ans += x;
    }

    std::cout << ans;

    return 0;
}
