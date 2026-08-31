    #include <bits/stdc++.h>
    #define task "dif"
    #define int long long
    #define ii std::pair<int, int>
    #define fi first
    #define se second
    #define pb push_back
    #define ins insert

    const int maxn = 3e5 + 7;
    int n, k;
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

        std::cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }

        std::map<int, int> mp;
        std::set<int> s;
        int ans = LLONG_MIN;
        if (n >= 100)
        {
            for (int i = k; i <= n; i++)
            {
                int cnt = 0;
                s.clear();
                for (int j = i - k + 1; j <= i; j++)
                {
                    s.insert(a[j]);
                }

                ans = std::max(ans, (int)s.size());
            }
        }
        else
        {
            for(int i = 1; i <= k; i++)
            {
                s.ins(a[i]);
                mp[a[i]]++;
            }

            ans = s.size();
            for (int i = k + 1; i <= n; i++) {
                mp[a[i - k]]--;
                if (!mp[a[i - k]]) s.erase(a[i - k]);
                if (!mp[a[i]]) s.insert(a[i]);
                mp[a[i]]++;
                ans = std::max(ans, (int)s.size());
            }
        }

        std::cout << ans;

        return 0;
    }
