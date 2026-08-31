#include <bits/stdc++.h>
#define task "num2"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int Mod = 1e9 + 7;
const int MOD = 17;

std::string l, r;
int dp[10000][17][15][2];

std::string dec(const std::string& s) {
    std::string result = s;
    int n = result.size();
    int carry = 1;

    for (int i = n - 1; i >= 0; --i) {
        if (result[i] < '0' + carry) {
            result[i] = '9';
            carry = 1;
        } else {
            result[i] = result[i] - carry;
            carry = 0;
            break;
        }
    }

    size_t i = result.find_first_not_of('0');
    if (i == std::string::npos) {
        return "0";
    }
    return result.substr(i);
}

int solve(std::string s, int pos, int mod, int last, bool tight) {
	//std::cout << s << " " << last << " " << mod << "\n";
	//std::cout << dp[pos][mod][last][tight] << "\n";

	//std::cout << last << "\n";

    if (pos == s.size())
    	return (mod == 0 && last != 10);

    if (dp[pos][mod][last][tight] != -1)
        return dp[pos][mod][last][tight];

    int k = (tight) ? (s[pos] - '0') : 9;

    int res = 0;

    for (int i = 0; i <= k; i++)
        if (i != last)
            res = (res + solve(s, pos + 1, (mod * 10 + i) % MOD, i, tight && (i == k))) % Mod;

    return dp[pos][mod][last][tight] = res;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> l >> r;

    memset(dp, -1, sizeof dp);
    int cR = solve(r, 0, 0, 10, 1);
    memset(dp, -1, sizeof dp);
    int cL = solve(dec(l), 0, 0, 10, 1);

    if (l.size() == 1) cL = 0;
    if (r.size() == 1) cR = 0;

    //std::cout << dec(l) << " " << cL << "\n";
    //std::cout << r << " " << cR << "\n";

    std::cout << (cR - cL + Mod) % Mod;

    return 0;
}
