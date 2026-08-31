#include <bits/stdc++.h>
#define task "photo"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int n;
int pos[6][maxn], b[maxn];

bool cmp(int x, int y){
    int s = 0;
    for (int j = 1; j <= 5; j++){
        if (pos[j][x] < pos[j][y]){
            s++;
        }else{
            s--;
        }
    }

    return s > 0;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            std::cin >> x;
            pos[i][x] = j;
        }
    }

    for (int i = 1; i <= n; i++){
        b[i] = i;
    }

    std::sort(b + 1, b + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        std::cout << b[i] << " ";
    }

    return 0;
}
