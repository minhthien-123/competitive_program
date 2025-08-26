#include <bits/stdc++.h>

long long i, n, j, en, beg, a[1000005], arr[1000005], prf[1000005];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("spsum5.inp", "r",stdin);
    std::freopen("spsum5.out", "w",stdout);

    std::cin >> n;
    for (i = 1; i <= n; i++) std::cin >> a[i];

    prf[0] = 0;
    for (i = 1; i <= n; i++) prf[i] = prf[i - 1] + a[i];

    arr[n] = prf[n];
    for (i = n - 1; i > 0; i--) arr[i] = std::max(arr[i + 1], prf[i]);

    /*for (i = 0; i < n; i++) cout << arr[i] << " ";
    std::cout << "\n";
    for (i = 0; i < n; i++) cout << prf[i] << " ";
    std::cout << "\n";*/

    i = 1; j = 0;
    beg = 0; en = 0;

    while (i <= n && j <= n){
        while (i <= n && prf[j] < arr[i]) i++;

        //std::cout << i - j << " ";

        if (i - j - 1 > en - beg){
            en  = i - 1;
            beg = j + 1;
        }

        //std::cout << i << " " << j << "\n";

        j++;
    }

    std::cout << beg << " " << en;

    return 0;
}
