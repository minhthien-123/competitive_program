#include <bits/stdc++.h>
#define task "19cos"
#define ll long long

int n, a[1000005], d, ans = INT_MIN;
bool flag;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    d = 1;
    flag = true;
    for (int i = 1; i < n; i++){
        if (flag){
            d++;
            if (a[i] > a[i + 1])
                flag = false;
        }else{
            d++;
            if (a[i] < a[i + 1]){
                flag = true;
                d = 1;
            }
        }

        ans = std::max(ans, d);
    }

    std::cout << ans;

    return 0;
}
