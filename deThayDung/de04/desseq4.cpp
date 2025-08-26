#include <bits/stdc++.h>
#define ll long long

ll i, n, ans, res, beg, en, a[1000005];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("desseq4.inp", "r", stdin);
    std::freopen("desseq4.out", "w", stdout);

    std::cin >> n;
    for (i = 1; i <= n; i++)
        std::cin >> a[i];

    ans = 1;
    i = 1;
    while (i < n){
        while (a[i] > a[i + 1] && i < n){
            ans++;
            i++;
        }

        if (ans > res){
            res = ans;
            en = i;
            beg = i - ans + 1;
            ans = 1;
        }

        i++;
    }

    std::cout << beg << " " << en;

    return 0;
}