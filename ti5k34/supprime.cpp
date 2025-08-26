#include <bits/stdc++.h>
#define task "supprime"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

bool solve(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int dem(int t){
    int ans = 1;
    while (t > 0){
        ans *= 10;
        t /= 10;
    }

    return ans / 10;
}

int t;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> t;

    if (t == 0){
        std::cout << "NO";
        return 0;
    }

    int tmp = dem(t);
    while (t > 0){
        if (!solve(t)){
            std::cout << "NO";
            return 0;
        }
        //std::cout << tmp << " ";
        //std::cout << t << " " << (int)(t / tmp) * tmp << "\n";
        t = t - ((int)(t / tmp) * tmp);
        tmp /= 10;
    }

    std::cout << "YES";

    return 0;
}