#include <bits/stdc++.h>

long long n, x, a[1000005], ans = 0;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> x;
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    for (int i = 1; i < n; i++){
        int tmp = a[i] + a[i + 1];
        if (tmp > x){
            int add = tmp - x;
            ans += add;
            if (add < a[i + 1]){
                a[i + 1] -= add;
            }else{
                add -= a[i + 1];
                a[i + 1] = 0;
                a[i] -= add;
            }
        }
    }

    std::cout << ans;

    return 0;
}
