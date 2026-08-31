#include "testlib.h"
#include <bits/stdc++.h>
#define ll long long

#define task "csdk"
const ll test = 1;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    for (ll i = 1; i <= test; i++){
        ll n, k;
        n = rnd.next(1, 10);
        k = rnd.next(1, 10);
        ll a[n], d[10];
        for (int i = 1; i <= n; i++){
            a[n] = rnd.next(1, 10);
        }

        for (int i = 1; i <= n; i++){
            a[i] = a[i - 1] + a[i];
        }

        std::cout << n << " " << k << "\n";
        for (int i = 1; i <= n; i++){
            std::cout << a[i] << " ";
        }
        std::cout << "\n";

        ll ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if ((a[j] - a[i]) % k == 0){
                    ans++;
                }
            }
        }

        for (int i = 1; i <= n; i++){
            if (a[i] == 0){
                ans++;
            }
        }

        std::cout << ans << " ";

        for (int i = 1; i <= n; i++){
            a[i] = a[i] % k;
        }

        for (int i = 1; i <= n; i++)
        {
            a[i] += a[i - 1];
            a[i] %= k;
            d[a[i]]++;
        }

        /*for (int i = 1; i <= n; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";*/

        ans = d[0];
        for (int i = 1; i <= n; i++)
        {
            d[a[i]]--;
            if (d[a[i]] > 0)
            {
                ans += d[a[i]];
            }
        }

        std::cout << ans;
    }
}