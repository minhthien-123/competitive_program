#include <bits/stdc++.h>
#define int long long

int n, dp[2][5007];
std::string s;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> s;

	for (int i = n - 1; i >= 0; i--){
		dp[i % 2][i] = 0;
		if (i + 1 < n)
            if (s[i] != s[i + 1])
                dp[i % 2][i + 1] = 1;
		for (int j = i + 2; j < n; j++)
			if (s[i] == s[j])
				dp[i % 2][j] = dp[1 - i % 2][j - 1];
			else
				dp[i % 2][j] = std::min(dp[i % 2][j - 1], dp[1 - i % 2][j]) + 1;
	}

	std::cout << dp[0][n - 1];

    return 0;
}
