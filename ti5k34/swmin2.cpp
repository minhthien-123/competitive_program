#include <bits/stdc++.h>
#define task "swmin2"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz size()

const int maxn = 1e6 + 7;
int n;
int a[maxn], Res[maxn];
bool check[maxn];
std::vector<int> res, v;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    int tmp = a[0];
    for (int i = 0; i < n; i++){
        if (a[i] > tmp){
            res.pb(i);
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i] <= tmp){
            res.pb(i);
        }
    }

    /*for (int i = 0; i < n; i++){
        std::cout << res[i] << " ";
    }
    std::cout << "\n";*/

    for (int i = 0; i < n; i++)
        if (res[i] == 0)
            tmp = i;

    //std::cout << tmp << "\n";

    for (int i = 0; i < tmp; i++){
        if (res[i] < tmp){
            check[res[i]] = true;
        }
    }

    for (int i = tmp + 1; i < n; i++){
        if (res[i] > tmp){
            check[res[i]] = true;
        }
    }

    for (int i = 0; i < n; i++){
        if (!check[res[i]] && res[i] != 0){
            v.pb(res[i]);
        }
    }

    /*for (int i : v){
        std::cout << i << " ";
    }
    std::cout << "\n\n";*/

    int cmp = 0;
    for (int i = 0; i < n; i++){
        if (!check[i] && i != tmp){
            //std::cout << i << "\n";
            Res[i] = v[cmp++];
        }else if (check[i]){
            Res[i] = i;
        }
    }

    Res[tmp] = 0;

    /*for (int i = 0; i < tmp; i++)
        std::cout << res[i] + 1 << " ";
    std::cout << "\n";
    for (int i = tmp + 1; i < n; i++)
        std::cout << res[i] + 1 << " ";
    std::cout << "\n";*/
    int d = 0;
    for (int i = 0; i < n; i++){
        if (Res[i] != i && (i != tmp)){
            d++;
        }
    }
    std::cout << d << "\n";
    /*for (int i = 0; i < n; i++)
        std::cout << check[i] << " ";*/
    //std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << Res[i] + 1 << " ";

    return 0;
}
