#include <iostream>
#include <vector>
#include <cstring> // For memset function

using namespace std;

int count_palindromic_ways(int k, int m, string s, vector<pair<int, int>>& segments) {
    int n = s.length();
    vector<long long> dp(n + 1, 0); // dp array, using long long to avoid overflow

    // Initialize dp[0] to 1 (one way to choose nothing)
    dp[0] = 1;

    // Convert segments to 0-based index
    for (auto& segment : segments) {
        int l = segment.first - 1; // Convert to 0-based index
        int r = segment.second - 1; // Convert to 0-based index

        // Update dp array from right to left to avoid overwriting issues
        for (int i = n; i > l; --i) {
            dp[i] += dp[i - (r - l + 1)];
        }
    }

    // Calculate ways for the last segment of length m
    for (int i = n; i >= m; --i) {
        dp[i] += dp[i - m];
    }

    // The answer is the number of ways to form a palindrome from start to end of the string
    return dp[n];
}

int main() {
    int k, m;
    cin >> k >> m;

    string s;
    cin >> s;

    vector<pair<int, int>> segments;
    for (int i = 0; i < k - 1; ++i) {
        int l, r;
        cin >> l >> r;
        segments.push_back({l, r});
    }

    int result = count_palindromic_ways(k, m, s, segments);
    cout << result << endl;

    return 0;
}

