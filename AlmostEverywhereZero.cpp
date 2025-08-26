#include <bits/stdc++.h>
#define int long long

int n, k;
std::string s;
int dp[107][107][2];
std::map<int, int> m;

int digit(int pos, int cnt, int flag, std::map<int, int> m){
    if(cnt > k) return 0;

    if(pos == s.size()){
        if(cnt == k) return 1;
        return 0;
    }

    if(dp[pos][cnt][flag] != -1) return dp[pos][cnt][flag];

    int res = 0, tmp;

    if(flag != 0)
        tmp = s[pos] - '0';
    else
        tmp = 9;

    for(int dgt = 0; dgt <= tmp; dgt++){
        int ncnt = cnt;
        if(dgt != 0) ncnt++, m[dgt]++;
        res += digit(pos + 1, ncnt, flag & (dgt == tmp), m);
        m[dgt]--;
        if (m[dgt] == 0)
            ncnt--;
    }

    dp[pos][cnt][flag] = res;
    return res;
}

signed main (){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("AlmostEverywhereZero.inp", "r", stdin);
    std::freopen("AlmostEverywhereZero.out", "w", stdout);

    std::cin >> s >> k;
    memset(dp, -1, sizeof(dp));
    std::cout << digit(0, 0, 1, m);

    return 0;
}
