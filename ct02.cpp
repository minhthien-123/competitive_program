#include <bits/stdc++.h>

const long long maxn = 100005;
long long m, n, a[maxn], b[maxn], i, j;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("ct02.inp", "r", stdin);
    std::freopen("ct02.out", "w", stdout);

    std::cin >> n >> m;
    for (i = 0; i < n; ++i) std::cin >> a[i];
    for (i = 0; i < m; ++i) std::cin >> b[i];

    i = 0; j = 0;
    while (i < n && j < m){
        if (a[i] < b[j])
            i++;
        else{
            std::cout << i << " ";
            j++;
        }

        //std::cout << i << " " << j << "\n";
    }

    while (j < m){
        std::cout << i << " ";
        j++;
    }

    return 0;
}


//1 6 9 13 18 18
//2 3 8 13 15 21 25
//1 1 2 3  4  6  6
