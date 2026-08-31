#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e5 + 7;
int t;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> t;
    while (t--){
        int n, a[maxn], b[maxn], c[maxn];
        bool flag = true;
        std::cin >> n;
        for (int i = 1; i < n; i++)
            std::cin >> b[i];
        memset(a, 0, sizeof(a));

        for (int i = 0; i < n; i++){
            a[i] |= b[i];
            a[i + 1] |= b[i];
        }

        for (int i = 1; i < n; i++)
            c[i] =  a[i] & a[i + 1];

        //for (int i = 1; i < n; i++)
            //std::cout << c[i] << " ";
        //std::cout << "\n";

        for (int i = 1; i < n; i++)
            if (c[i] != b[i])
                flag = false;

        if (flag){
            for (int i = 1; i <= n ; i++)
                std::cout << a[i] << " ";
            std::cout << "\n";
        }else
            std::cout << "-1\n";

        //for (int i = 0; i < n; i++)
            //std::cout << a[i] << " ";
        //std::cout << "\n";
    }

    return 0;
}
