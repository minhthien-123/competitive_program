#include <bits/stdc++.h>

const long long maxn = 1e6;
long long n, k, m, a[maxn], i, inc = 1, line = 0, res = 0, x;

bool cmp(long long x, long long y){
    long long tmp_x = 0, tmp_y = 0;
    bool is_ok = x < y;

    x /= m;
    y /= m;
    if (x % m == 0){
        x++;
        tmp_x = 1;
    }

    if (y % m == 0){
        y++;
        tmp_y = 1;
    }

    if (x == y)
        if (tmp_x == tmp_y) return is_ok;
        else                return tmp_x > tmp_y;
    else
        return x < y;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("catday.inp", "r", stdin);
    std::freopen("catday.out", "w", stdout);

    std::cin >> n >> k >> m;

    for (i = 1; i <= n; i++){
        std::cin >> a[i];
        if (a[i] < m) inc++;
    }

    std::sort(a + 1, a + n + 1, cmp);

    for (i = 1; i <= n; i++)
        std::cout << a[i] << " ";

    std::cout << "\n";

    /*for (i = inc; i <= n; i++){
        if (a[i] % m == 0){
            x = a[i] / m;
            if (line + x < k){
                line += x;
                res += x - 1;
            }else{
                x = line - x;
                res += x;
                //std::cout << res;
                //return 0;
            }
        }else{
            x = a[i] / m;
            if (line + x < k){
                line += x;
                res += x;
            }else{
                x = line - x;
                res += x;
            }
        }

        std::cout << res << " ";
    }*/

    return 0;
}