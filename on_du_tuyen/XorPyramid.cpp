#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e5 + 7;
int n, a[maxn], f[maxn], dp[maxn], ans;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;

    for (int i = 0; i < n; i++){
        int tmp = i, cnt = 0;
        while (tmp){
            tmp /= 2;
            cnt += tmp;
        }
        f[i] = cnt;
    }

    for (int i = 0, x; i < n; i++){
        std::cin >> x;
        if ((f[n - 1] - f[n - i - 1] - f[i]) == 0)
            ans ^= x;
    }

    std::cout << ans;

    return 0;
}
