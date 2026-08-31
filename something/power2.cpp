#include <bits/stdc++.h>

long long x, n, m;

long long power(long long x, long long y, long long m)
{
    if (y == 0)
        return 1;
    long long tmp = power(x, y / 2, m);
    if (y % 2 == 0)
        return (tmp * tmp) % m;
    else
        return tmp * tmp % m * x % m;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long x, n, m;
    while (std::cin >> x >> n >> m)
        std::cout << power(x, n, m) << "\n";
}
