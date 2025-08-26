#include <bits/stdc++.h>
#define task "timm"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;

    int ans = 0;

    for (int a = 1; a * a * a * a * a <= n; a++){
        int tmp = a * a;
        //if (n % tmp != 0) continue;

        tmp = n / tmp;
        //std::cout << tmp << "\n";

        for (int c = 2; c * c <= tmp; c++){
            int cmp = c * c;
            //if (tmp % cmp != 0) continue;

            int b = tmp / cmp;

            /*for (int i = a + 1; i <= std::min(b, c - 1); i++){
                std::cout << a << " " << i << " " << c << "\n";
            }*/

            int temp = std::min(b, c - 1);

            if (temp > a){
                //std::cout << a << " " << b << " " << c << "\n";
                ans += temp - a;
            }

            //if (a < b && b < c){
                //std::cout << a << " " << b << " " << c << "\n";
            //}

        }
    }

    std::cout << ans;

    return 0;
}

// a * a * b * c * c <= n
// a < b < c
// n >= a^5
// a <= sqrt5(n)
// a = 1
// 1 < c <= 10
// 100 / 4 = 25
//
