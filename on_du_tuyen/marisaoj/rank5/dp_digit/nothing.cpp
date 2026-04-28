#include <bits/stdc++.h>
#define task "nopalind"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 18;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int l, r;
int n;
int digit[maxn + 7];
// mở thêm 1 để dùng 10 làm sentinel "chưa có chữ số"
int dp[maxn + 7][11][11];

int f(int pos, int prelast, int last, bool flag)
{
    if (pos == n)
    {
        return 1;
    }

    int &memo = dp[pos][prelast][last];
    if (flag && memo != -1)
    {
        return memo;
    }

    int lim = flag ? 9 : digit[pos];
    int res = 0;
    for (int i = 0; i <= lim; i++)
    {
        // Nếu vẫn ở trạng thái leading zeros (chưa có chữ số nào khác 0)
        bool still_leading = (last == 10 && prelast == 10 && i == 0);

        // kiểm tra điều kiện (so sánh với last/prelast hiện tại)
        if (i == last || i == prelast)
        {
            continue;
        }

        // cập nhật prelast/last: nếu vẫn leading thì giữ sentinel 10
        int npre = last;
        int nlast = i;
        if (last == 10 && i == 0)
        {
            npre = 10;
            nlast = 10;
        }
        // nếu trước đó chưa có chữ số (prelast==10, last==10) nhưng i != 0
        // thì npre = last (10) và nlast = i — đúng

        res += f(pos + 1, npre, nlast, flag || (i < lim));
    }

    if (flag)
    {
        memo = res;
    }

    return res;
}

int g(int k)
{
    std::vector<int> tmp;
    if (k == 0)
        tmp.pb(0); // xử lý k == 0
    while (k > 0)
    {
        tmp.pb(k % 10);
        k /= 10;
    }
    std::reverse(tmp.begin(), tmp.end());
    n = (int)tmp.size();
    for (int i = 0; i < n; ++i)
        digit[i] = tmp[i];

    memset(dp, -1, sizeof dp);
    // dùng 10 làm sentinel (chưa có chữ số)
    return f(0, 10, 10, 0);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> l >> r;
    std::cout << g(r) - g(l - 1);

    return 0;
}
