#include <bits/stdc++.h>
#define task "asummin"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r")){
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int n, m;
    std::cin >> n >> m;
    ii a[n + 7], b[m + 7];
    for (int i = 1; i <= n; i++){
        std::cin >> a[i].fi;
        a[i].se = i;
    }

    for (int i = 1; i <= m; i++){
        std::cin >> b[i].fi;
        b[i].se = i;
    }
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + m + 1);

    int i = 1, j = m, res = abs(a[i].fi + b[j].fi);
    ii ans = {a[i].se, b[j].se};

    while (i < n || j > 1){
        if (i == n){
            j--;
        }
        else if (j == 1){
            i++;
        }else if (abs(a[i].fi + b[j].fi) < abs(a[i].fi + b[j - 1].fi)){
            i++;
        }else{
            j--;
        }

        //std::cout << a[i].se << " " << b[j].se << "\n";

        if (abs(a[i].fi + b[j].fi) < res && i <= n && j >= 1){
            res = abs(a[i].fi + b[j].fi);
            ans = {a[i].se, b[j].se};
            //std::cout << a[i].fi << " " << b[j].fi << "\n";
        }

        //res = std::min(res, abs(a[i] + b[j]));
    }

    //std::cout << res << "\n";
    std::cout << ans.fi<< " " << ans.se;

    return 0;
}

//20 100
//817 -840 242 684 654 -654 434 -116 -364 282 960 252 661 659 501 -986 573 -482 203 -447
//335 -292 -885 -295 333 -655 -450 -145 844 140 -232 191 720 754 137 701 -173 -950 265 214 0 -779 800 -863 -835 -290 47 455 -41 -709 -640 -888 366 -397 488 288 837 307 157 -553 -916 -187 574 430 550 441 665 144 736 131 -927 927 95 966 526 -646 -220 -724 610 848 122 -58 -463 360 -618 979 -518 202 -151 637 -463 107 857 638 648 -690 -513 915 671 -143 312 -333 236 -775 -433 408 -291 -745 845 -906 606 582 -98 -259 -547 396 985 956 464 586
