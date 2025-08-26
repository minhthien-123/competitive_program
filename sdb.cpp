#include <bits/stdc++.h>
#define task "sdb"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int t, a, b;

int solve(int n){
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans ++;
            if (n / i != i)
            {
                ans ++;
            }
        }
    }

    return ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> t;
    while (t--){
        std::cin >> a >> b;
        int res = 0;
        for (int j = a; j <= b; j++){
            //cout << j << " " << solve(j) << "\n";
            if (j % 3 == 0 && solve(j) == 9) res++;
        }
        std::cout << res << "\n";
    }
}

/*a /= 9; b /= 9;
        a = sqrt(a);
        if ((a == 0) || (a == 1)) a = 2;
        b = sqrt(b);
        //cout << a << " " << b << "\n";
        if (b <= 1) cout << 0 << "\n";
        else{
            int ans = b - a + 1;
            a = a + (3 - a % 3);
            b = b - b % 3;
            //cout << a << " " << b << "\n";
            a /= 3; b /= 3;
            cout << ans - (b - a + 1) << "\n";
        }*/
