#include <bits/stdc++.h>
#define ll long long

const ll maxn = 1e6;

bool a[maxn + 5];
ll n, k, ans = 0;;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("cppri3.inp", "r", stdin);
    std::freopen("cppri3.out", "w", stdout);


    for (ll i = 2; i <= maxn; i++)
        a[i] = true;
    a[1] = false;
    a[0] = false;
    for (ll i = 2; i <= maxn; i++)
        if (a[i])
            for (ll j = i * i; j <= maxn; j += i)
                a[j] = false;

    std::cin >> n >> k;
    for (int i = 1; i <= n - k; i++)
        if (a[i] && a[i + k])
            ans++;
    std::cout << ans;

    return 0;
}