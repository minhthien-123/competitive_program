#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 20230928;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    string P;
    cin >> n >> P;
    int m = P.size();

    // 1) build KMP failure
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i)
    {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            ++j;
        pi[i] = j;
    }

    // 2) build automaton next_state[state][bit]
    // state = hiện tại đã khớp prefix độ dài state
    vector<array<int, 2>> nxt(m + 1);
    for (int st = 0; st <= m; ++st)
    {
        for (int b = 0; b < 2; ++b)
        {
            char c = char('0' + b);
            if (st < m && c == P[st])
            {
                nxt[st][b] = st + 1;
            }
            else
            {
                if (st == 0)
                {
                    nxt[st][b] = 0;
                }
                else
                {
                    nxt[st][b] = nxt[pi[st - 1]][b];
                }
            }
        }
    }
    // trạng thái m là “đã gặp P” -> ta sẽ không chuyển vào

    // 3) DP rolling: dp_cur[k] = số xâu độ dài i mà đang ở state k (chưa gặp P)
    vector<int> dp_cur(m, 0), dp_nxt(m, 0);
    dp_cur[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        fill(dp_nxt.begin(), dp_nxt.end(), 0);
        for (int st = 0; st < m; ++st)
        {
            if (!dp_cur[st])
                continue;
            int ways = dp_cur[st];
            // thêm bit = 0 hoặc 1
            for (int b = 0; b < 2; ++b)
            {
                int u = nxt[st][b];
                if (u < m)
                { // chỉ giữ nếu chưa vào state m
                    dp_nxt[u] = (dp_nxt[u] + ways) % MOD;
                }
            }
        }
        swap(dp_cur, dp_nxt);
    }

    // tổng mọi state 0..m-1
    ll ans = 0;
    for (int st = 0; st < m; ++st)
    {
        ans = (ans + dp_cur[st]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
