#include <bits/stdc++.h>
#define task "fourdiv"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e6;
bool f[maxn + 7];
int t;

void sieve(){
    memset(f, true, sizeof f);
    f[0] = f[1] = false;
    for (int i = 2; i * i <= maxn; i++)
        if (f[i])
            for (int j = i * i; j <= maxn; j += i)
                f[j] = false;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    sieve();

    std::cin >> t;
    while (t--){
        int d;
        std::cin >> d;
        int a = d + 1;
        while (!f[a]) a++;
        int b = d + a;
        while (!f[b]) b++;

        std::cout << a * b << "\n";
    }

    return 0;
}
