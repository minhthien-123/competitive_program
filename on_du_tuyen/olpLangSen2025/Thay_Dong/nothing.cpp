#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//--- các tham số hash
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll B1 = 91138233;
const ll B2 = 97266353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string T;
    cin >> n >> T;

    // 1) Mã hóa T thành hash đôi và tính powB^k
    vector<ll> pow1(n + 1, 1), pow2(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        pow1[i] = (pow1[i - 1] * B1) % MOD1;
        pow2[i] = (pow2[i - 1] * B2) % MOD2;
    }

    ll hashT1 = 0, hashT2 = 0;
    for (char c : T)
    {
        int v = c - '0' + 1;
        hashT1 = (hashT1 * B1 + v) % MOD1;
        hashT2 = (hashT2 * B2 + v) % MOD2;
    }

    // 2) Stream S = "1","2","3",... đến 10^15
    const unsigned long long LIMIT = 1000000000000000ULL;
    deque<char> window;
    ll hashW1 = 0, hashW2 = 0;
    ll pos = 0;

    for (unsigned long long x = 1; x <= LIMIT; x++)
    {
        string s = to_string(x);
        for (char c : s)
        {
            pos++;
            int v = c - '0' + 1;

            // thêm vào hash
            hashW1 = (hashW1 * B1 + v) % MOD1;
            hashW2 = (hashW2 * B2 + v) % MOD2;
            window.push_back(c);

            // nếu cửa sổ > n, pop front
            if ((int)window.size() > n)
            {
                int u = window.front() - '0' + 1;
                window.pop_front();
                hashW1 = (hashW1 - u * pow1[n] % MOD1 + MOD1) % MOD1;
                hashW2 = (hashW2 - u * pow2[n] % MOD2 + MOD2) % MOD2;
            }

            // kiểm tra khi đủ n
            if ((int)window.size() == n && hashW1 == hashT1 && hashW2 == hashT2)
            {
                // xác thực lần cuối để phòng rare collision
                bool ok = true;
                for (int i = 0; i < n; i++)
                {
                    if (window[i] != T[i])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    cout << pos << "\n";
                    return 0;
                }
            }
        }
    }

    // không tìm thấy trong đến 10^15
    cout << -1 << "\n";
    return 0;
}
