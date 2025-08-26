#include <bits/stdc++.h>
#define task "SumofXORFunctions"
#define int long long

bool flag(int val, int bit){
    return (val >> bit) & 1;
}

const int maxn = 3e5 + 7;
int a[maxn], s[maxn];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    for (int bit = 0; bit <= 29; bit++){
        cnt[0] = cnt[1] = sum[0] = sum[1], sum = 0;
        for (int i = 1; i <= n; i++)
            if (flag(a[i], bit)) s[i] = 1;
            else                 s[i] = 0;
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] ^ a[i];
    }

    return 0;
}
