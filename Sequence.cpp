#include <bits/stdc++.h>
#define int long long

bool flag;
int n, s = 0, ans1 = 0, ans2, a[1000007];

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    s = 0;
    ans1 = 0;

    for (int i = 1; i <= n; i++){
        s += a[i];
        if (i % 2 == 1){
            if (s <= 0){
                ans1 += (1 - s);
                s = 1;
            }
        }else{
            if (s >= 0){
                ans1 += (s + 1);
                s = -1;
            }
        }
    }

    ans2 = 0;
    s = 0;

    for (int i = 1; i <= n; i++){
        s += a[i];
        if (i % 2 != 1){
            if (s <= 0){
                ans2 += (1 - s);
                s = 1;
            }
        }else{
            if (s >= 0){
                ans2 += (s + 1);
                s = -1;
            }
        }
    }

    //std::cout << ans1 << " " << ans2 << "\n";

    std::cout << std::min(ans1, ans2);

    return 0;
}
