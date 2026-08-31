#include <bits/stdc++.h>
#define task "num1"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

ll dp[maxn][13];
std::vector<int> v = {0, 2, 4, 5, 6, 7, 8, 9};
ll n;

int solve(int n) {
    for (int k : v) {
        if (k != 0) {
            dp[1][k % 13]++;
        }
    }
    
    for (int i = 2; i <= n; ++i)
        for (int m = 0; m < 13; m++)
            for (int k : v) {
                int new_m = (m * 10 + k) % 13;
                dp[i][new_m] = (dp[i][new_m] + dp[i - 1][m]) % mod;
            }
    
    return dp[n][0]; 
}


int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> n;

	std::cout << solve(n);

	return 0;
}