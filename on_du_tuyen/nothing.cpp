#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    if (!(cin >> S))
        return 0;
    int n = (int)S.size();

    // dp[i][j]: số xâu khác nhau (không rỗng) từ prefix 1..i, kết thúc bằng chữ cái j (j=0..25)
    vector<array<ll, 26>> dp(n + 1);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 26; j++)
            dp[i][j] = 0;

    // last[c] = vị trí cuối cùng (1-based) đã xuất hiện ký tự c; 0 nếu chưa xuất hiện
    vector<int> last(26, 0);

    auto sum_dp = [&](int idx) -> ll
    {
        if (idx < 0)
            return 0;
        ll s = 0;
        for (int k = 0; k < 26; k++)
        {
            s += dp[idx][k];
            if (s >= MOD)
                s -= MOD;
        }
        return s;
    };

    for (int i = 1; i <= n; ++i)
    {
        int c = S[i - 1] - 'a';
        // 1) không chọn i: carry over tất cả xâu từ i-1
        for (int k = 0; k < 26; k++)
        {
            dp[i][k] = dp[i - 1][k];
        }

        // 2) chọn i: tạo các xâu mới kết thúc bằng c
        ll new_count = 1 + sum_dp(i - 2); // 1 cho xâu chỉ chứa S[i], + tất cả xâu từ i-2 appended by c
        if (new_count >= MOD)
            new_count -= MOD;

        ll to_sub = 0;
        if (last[c] != 0)
        {
            int p = last[c];
            to_sub = 1 + sum_dp(p - 2);
            if (to_sub >= MOD)
                to_sub -= MOD;
        }

        ll add = (new_count - to_sub) % MOD;
        if (add < 0)
            add += MOD;

        dp[i][c] += add;
        if (dp[i][c] >= MOD)
            dp[i][c] -= MOD;

        last[c] = i;
    }

    // Kết quả là tổng số xâu khác nhau (không rỗng) từ toàn bộ chuỗi => sum dp[n][*]
    ll ans = 0;
    for (int k = 0; k < 26; k++)
    {
        ans += dp[n][k];
        if (ans >= MOD)
            ans -= MOD;
    }

    cout << ans % MOD << '\n';
    return 0;
}
