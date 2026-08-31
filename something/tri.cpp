    #include <bits/stdc++.h>
    #define task "tri"
    #define int long long
    #define ii std::pair<int, int>
    #define fi first
    #define se second
    #define pb push_back
    #define ins insert

    signed main()
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0); std::cout.tie(0);

        if (std::fopen(task".inp", "r"))
        {
            std::freopen(task".inp", "r", stdin);
            std::freopen(task".out", "w", stdout);
        }

        long double x, y, a, b, c;
        std::cin >> x >> y;
        a = (x + y) - sqrt(2 * x * (x + y));
        b = y - a;
        c = sqrt(a * a + b * b);

        std::cout << std::fixed << std::setprecision(5) << std::min(a, b) << " " << std::max(a, b) << " " << c;

        return 0;
    }
