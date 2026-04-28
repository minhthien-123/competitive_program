#include <bits/stdc++.h>

int n, a[1000005], res = 0, ans = 0, i, tmp;

bool ss(int a, int b){
    return a > b;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("higtil.inp", "r", stdin);
    std::freopen("higtil.out", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(a, a + n, ss);

    for (i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";

    ans = 0;
    for(i = 0; i <= tmp; i++){
        tmp = a[i];
    }

    std::cout << i;

    return 0;
}