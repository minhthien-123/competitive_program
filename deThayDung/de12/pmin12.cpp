#include <bits/stdc++.h>
#define ma LLONG_MAX
#define mn LLONG_MIN

long long n, a[1000005], c0, i, cd, vt0;
long long mindDex, mind2Dex, maxdDex, minaDex, maxaDex, maxa2Dex;
long long maxd = mn, mind = ma, mind2 = ma, maxa = mn, mina = ma, maxa2 = mn;
long long prodA = ma, prodD = ma, prodDA = ma, prodAD = ma, prodMin = ma;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("pmin12.inp", "r", stdin);
    std::freopen("pmin12.out", "w", stdout);

    std::cin >> n;
    for (i = 1; i <= n; i++){
        std::cin >> a[i];
        if (a[i] > 0){
            cd = 1;
            if (a[i] > maxd){
                maxd = a[i];
                maxdDex = i;
            }
            if (a[i] < mind){
                mind = a[i];
                mindDex = i;
            }
        }else if (a[i] < 0){
            if (a[i] < mina){
                mina = a[i];
                minaDex = i;
            }
            if (a[i] > maxa){
                maxa = a[i];
                maxaDex = i;
            }
        }else{
            c0 = 1;
            vt0 = i;
        }
    }

    for (i = 1; i <= n; i++){
        if (i != mindDex)
            if (a[i] > 0)
                if (a[i] < mind2){
                    mind2 = a[i];
                    mind2Dex = i;
                }
        if (i != maxaDex)
            if (a[i] < 0)
                if (a[i] > maxa2){
                    maxa2 = a[i];
                    maxa2Dex = i;
                }
    }

    /*std::sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";

    std::cout << "duong lon nhat " << maxd  << "\n";
    std::cout << "duong be nhat "  << mind  << "\n";
    std::cout << "duong be nhi "   << mind2 << "\n";
    std::cout << "am be nhat "     << mina  << "\n";
    std::cout << "am lon nhat "    << maxa  << "\n";
    std::cout << "am lon nhi "     << maxa2 << "\n";*/

    if (c0 == 1 && cd == 1){
        if (vt0 == 1) std::cout << vt0 << " " << vt0 + 1;
        else          std::cout << vt0 - 1 << " " << vt0;
        return 0;
    }

    if (maxa != mn && maxa2 != mn)
        prodA = maxa * maxa2;
    if (mind != ma && mind2 != ma)
        prodD = mind * mind2;
    if (maxa != mn && mind != ma)
        prodAD = maxa * mind;
    if (maxd != mn && mina != ma)
        prodDA = maxd * mina;

    prodMin = std::min(std::min(prodA, prodD), std::min(prodDA, prodAD));

    //std::cout << prodA << "\n" << prodD << "\n" << prodAD << "\n" << prodDA << "\n";
    //std::cout << prodMin << "\n";

    if (prodA == prodMin)
        std::cout << std::min(maxaDex, maxa2Dex) << " " << std::max(maxaDex, maxa2Dex);
    else if (prodD == prodMin)
        std::cout << std::min(mindDex, mind2Dex) << " " << std::max(mindDex, mind2Dex);
    else if (prodAD == prodMin)
        std::cout << std::min(maxaDex, mindDex)  << " " << std::max(maxaDex, mindDex);
    else
        std::cout << std::min(maxdDex, minaDex)  << " " << std::max(maxdDex, minaDex);

    return 0;
}