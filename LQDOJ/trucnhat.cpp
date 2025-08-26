#include <bits/stdc++.h>

const long long maxn = 5e6 + 9;
long long check[maxn];
long long res = 0, n;

int main(){
    for (long long i = 1; i <= maxn; i++)
        for (long long j = i; j <= maxn; j += i)
            check[j] += i;

    for (long long i = 1; i <= maxn; i++)
        if (check[i] < 2 * i)
            check[i] = 1;
        else
            check[i] = 0;

    std::cin >> n;
    res = 0;
    for (long long i, x; i < n; i++){
        std::cin >> x;
        if (check[x] == 1){
            res++;
            //std::cout << x << " " << res << "\n";
        }
    }

    std::cout << res;

    return 0;
}