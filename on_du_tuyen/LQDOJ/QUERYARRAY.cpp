#include <bits/stdc++.h>

int n, q, t, l, r, x, a[1000005];

int main(){
    std::cin >> n >> q;
    while (q--){
        std::cin >> t >> l >> r >> x;
        if (t == 1){
            a[l] += x;
            a[r + 1] -= x;
        }else{
            a[l] -= x;
            a[r + 1] += x;
        }
    }

    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    for (int i = 1; i <= n; i++)
        std::cout << a[i] << " ";
}