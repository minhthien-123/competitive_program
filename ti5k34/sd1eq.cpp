    #include <bits/stdc++.h>
    #define task "sd1eq"
    #define int long long
    #define ii std::pair<int, int>
    #define fi first
    #define se second
    #define pb push_back
    #define ins insert

    const int maxn = 1e6 + 7;
    const int inf = 1e18;

    int n;
    int a[maxn];

    signed main()
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0); std::cout.tie(0);

        if (std::fopen(task".inp", "r"))
        {
            std::freopen(task".inp", "r", stdin);
            std::freopen(task".out", "w", stdout);
        }

        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }

        int s = 0, ans = -inf;
        for (int i = 1; i <= n; i++)
        {
            s = std::max(s + a[i], a[i]);
            ans = std::max(ans, s);
        }

        std::cout << ans;

        return 0;
    }
