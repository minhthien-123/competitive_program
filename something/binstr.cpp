#include <bits/stdc++.h>

int n, ans[1000005], j, k;

void Try(int i){
    for (int j = 0; j <= 1; j++){
        ans[i] = j;
        if (i == n){
            for (int k = 1; k <= n; k++) std::cout << ans[k];
            std::cout << "\n";
        }else Try(i + 1);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("binstr.inp", "r", stdin);
    std::freopen("binstr.out", "w", stdout);

    std::cin >> n;

    Try(1);

    return 0;
}
