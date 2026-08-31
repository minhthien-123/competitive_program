#include <bits/stdc++.h>
#define task d13easytask
#define ll long long

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;

    for (int i = 0; i <= n; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 1; i * i <= n; i++)
        if (prime[i])
            for ()

    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        a[i] += a[i - 1];
    }



    return 0;
}
