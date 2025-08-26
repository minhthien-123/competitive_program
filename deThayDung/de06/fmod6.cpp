#include <bits/stdc++.h>
#define ll long long

ll n, F[2][2], M[2][2];
ll m = 1e9 + 7;

void fibonacci(ll f1[2][2], ll f2[2][2], ll m)
{
    ll a = (f1[0][0] * f2[0][0] % m + f1[0][1] * f2[1][0] % m) % m;
    ll b = (f1[0][0] * f2[0][1] % m + f1[0][1] * f2[1][1] % m) % m;
    ll c = (f1[1][0] * f2[0][0] % m + f1[1][1] * f2[1][0] % m) % m;
    ll d = (f1[1][0] * f2[0][1] % m + f1[1][1] * f2[1][1] % m) % m;
    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}

void power(ll f[2][2], ll n)
{
    if (n <= 1)
        return;
    power(f, n / 2);
    fibonacci(f, f, m);
    if (n % 2 != 0)
        fibonacci(f, M, m);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    // std::freopen("fmod6.inp", "r", stdin);
    // std::freopen("fmod6.out", "w", stdout);

    F[0][0] = F[0][1] = F[1][0] = 1;
    F[1][1] = 0;
    M[0][0] = M[0][1] = M[1][0] = 1;
    M[1][1] = 0;

    std::cin >> n;
    if (n == 0)
        std::cout << 0;
    else
    {
        power(F, n - 1);
        std::cout << F[0][0];
    }

    return 0;
}