#include <bits/stdc++.h>
#define task "socola"
#define ll long long

const int maxn = 1e5 + 7;

int n, q, c[maxn], d, k[maxn], m[maxn], a[maxn];
bool flag = true;

int res(int x, int k){
    if (x < k) return x;
    else       return 2 * k - x;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];

    std::sort(c + 1, c + n + 1);

    for (int i = 1; i <= q; i++)
        std::cin >> k[i] >> m[i];

    for (int i = 2; i <= q; i++)
        if (k[i] != k[i - 1])
            flag = false;

    if (flag){
        for (int i = 1; i <= n; i++)
            a[i] = res(c[i], k[1]);

        std::sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];

        //for (int i = 1; i <= n; i++)
            //std::cout << a[i] << " ";
        //std::cout << "\n";

        for (int i = 1; i <= q; i++)
            std::cout << a[m[i]] << "\n";
    }else{
        for (int i = 1; i <= q; i++){
            int l = 1, r = n, d = 0, ans = 0;
            while (d < m[i]){
                int ans1 = res(c[l], k[i]), ans2 = res(c[r], k[i]);

                if (ans1 <= ans2){
                    ans += ans1;
                    l++;
                }else{
                    ans += ans2;
                    r--;
                }


                d++;
            }

            std::cout << ans << "\n";
        }
    }

    return 0;
}
