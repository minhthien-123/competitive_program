#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e7 + 7;
int pre[maxn], divi[maxn];

void sub1(int l, int r){
    int ans = 0;
    for (int i = l; i <= r; i++){
        int d = 0;
        for (int j = 1; j <= i; j ++){
            if (i % j == 0){
                d++;
            }
        }

        if (d == 8){
            ans++;
        }
    }
    std::cout << ans << "\n";
}

void sub2(int l, int r){
    int ans = 0;
    for (int i = l; i <= r; i++){
        int d = 0;
        for (int j = 1; j * j <= i; j++){
            if (i % j == 0){
                d++;
                if (i / j != j){
                    d++;
                }
            }
        }
        if (d == 8){
            ans++;
        }
    }

    std::cout << ans << "\n";
}

void sub3(int t){
    for (int i = 1; i <= maxn; i++) {
        for (int j = i; j <= maxn; j += i) {
            divi[j]++;
        }
    }

    while (t--){
        int l, r;
        std::cin >> l >> r;

        int ans = 0;
        for (int i = l; i <= r; i++){
            if (divi[i] == 8){
                ans++;
            }
        }

        std::cout << ans << "\n";
    }
}

void sub4(int t) {
    for (int i = 1; i <= maxn; i++) {
        for (int j = i; j <= maxn; j += i) {
            divi[j]++;
        }
    }

    for (int i = 1; i <= maxn; i++) {
        pre[i] = pre[i - 1] + (divi[i] == 8);
    }

    while (t--){
        int l, r;
        std::cin >> l >> r;

        std::cout << pre[r] - pre[l - 1] << "\n";
    }
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int t;
    std::cin >> t;
    if (t <= 100){
        while (t--){
            int l, r;
            std::cin >> l >> r;
            if (r <= 100){
                sub1(l, r);
            }else if (r <= 1000){
                sub2(l, r);
            }
        }
    }else if (t <= 1000){
        sub3(t);
    }else{
        sub4(t);
    }

    return 0;
}
