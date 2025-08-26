#include <bits/stdc++.h>
#define task "DigitsParade"
#define int long long

const int mod = 13;
const int Mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int dp[maxn][20], f[maxn];
std::string s;

int digit(int pos, int sum){
    if (pos == (s.size() - 1)){
        if (sum % mod == 5) return 1;
        return 0;
    }

    if (dp[pos][sum] != -1) return dp[pos][sum] % Mod;

    int res = 0;

    if (s[pos] == '?'){
        //std::cout << pos << "\n";
        for (int dgt = 0; dgt <= 9; dgt++)
            res = (res + digit(pos + 1, sum + dgt * f[s.size() - pos - 1] % mod) % Mod) % Mod;
    }else
        res = (res + digit(pos + 1, sum + (s[pos] - '0') * f[s.size() - pos - 1] % mod) % Mod) % Mod;

    return dp[pos][sum] = res % Mod;
}

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> s;
    f[0] = 1;
    for (int i = 1; i <= s.size(); i++)
        f[i] = f[i - 1] * 10 % Mod;

    memset(dp, -1, sizeof(dp));

    std::cout << digit(0, 0) % Mod;

    return 0;
}
