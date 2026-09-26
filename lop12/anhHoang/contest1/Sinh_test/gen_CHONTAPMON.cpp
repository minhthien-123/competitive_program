#include <bits/stdc++.h>

using namespace std;

// ==========================================
// CẤU HÌNH VÀ HÀM RANDOM
// ==========================================
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_int(long long l, long long r)
{
    return uniform_int_distribution<long long>(l, r)(rng);
}

const int mod = 998244353;
long long add(long long x, long long y) { return (x + y) % mod; }
long long sub(long long x, long long y) { return (x - y + mod) % mod; }
long long mul(long long x, long long y) { return (x % mod * (y % mod)) % mod; }

// ==========================================
// CẤU TRÚC DỮ LIỆU CỦA NGƯỜI DÙNG (Để tạo Output)
// ==========================================
long long a[105][2005];
long long sum_arr[105];
long long dp[105][205];

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
void generate_output(string inp_file, string out_file)
{
    ifstream fin(inp_file);
    ofstream fout(out_file);

    int n, m;
    if (!(fin >> n >> m))
        return;

    for (int i = 1; i <= n; i++)
    {
        sum_arr[i] = 0;
        for (int j = 1; j <= m; j++)
        {
            fin >> a[i][j];
            sum_arr[i] = add(sum_arr[i], a[i][j]);
        }
    }

    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = mul(ans, add(sum_arr[i], 1));
    }
    ans = sub(ans, 1);

    long long res = 0;

    for (int j = 1; j <= m; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int diff = 0; diff <= 2 * n + 2; diff++)
            {
                dp[i][diff] = 0;
            }
        }

        dp[0][n + 1] = 1;

        for (int i = 1; i <= n; i++)
        {
            long long sum1 = sub(sum_arr[i], a[i][j]);
            for (int diff = 1; diff <= 2 * n + 1; diff++)
            {
                if (dp[i - 1][diff] == 0)
                    continue;

                dp[i][diff] = add(dp[i][diff], dp[i - 1][diff]);
                dp[i][diff + 1] = add(dp[i][diff + 1], mul(dp[i - 1][diff], a[i][j]));
                dp[i][diff - 1] = add(dp[i][diff - 1], mul(dp[i - 1][diff], sum1));
            }
        }

        for (int diff = n + 2; diff <= 2 * n + 1; diff++)
        {
            res = add(res, dp[n][diff]);
        }
    }

    ans = sub(ans, res);
    fout << ans << "\n";
}

// ==========================================
// HÀM XÁC ĐỊNH NHÓM TEST VÀ SINH INPUT
// ==========================================
int get_group(int t)
{
    if (t <= 2)
        return 1;
    if (t <= 4)
        return 2;
    if (t <= 7)
        return 3;
    if (t <= 10)
        return 4;
    if (t <= 13)
        return 5;
    if (t <= 16)
        return 6;
    if (t <= 19)
        return 7;
    if (t <= 22)
        return 8;
    if (t <= 27)
        return 9;
    if (t <= 32)
        return 10;
    if (t <= 40)
        return 11;
    return 12;
}

void generate_input(int t, string inp_file)
{
    ofstream fout(inp_file);
    int group = get_group(t);

    int n = 2, m = 2;
    long long max_a = 1; // < 2

    // Áp dụng đúng các mốc giới hạn n, m cho từng nhóm
    if (group == 1)
    {
        n = 2;
        m = 2;
        max_a = 1;
    }
    else if (group == 2)
    {
        n = 2;
        m = 3;
        max_a = 1;
    }
    else if (group == 3)
    {
        n = 5;
        m = 2;
        max_a = 1;
    }
    else if (group == 4)
    {
        n = 5;
        m = 3;
        max_a = 1;
    }
    else if (group == 5)
    {
        n = 10;
        m = 2;
        max_a = 1;
    }
    else if (group == 6)
    {
        n = 10;
        m = 3;
        max_a = 1;
    }
    else if (group == 7)
    {
        n = 10;
        m = 2;
        max_a = 999;
    }
    else if (group == 8)
    {
        n = 10;
        m = 3;
        max_a = 999;
    }
    else if (group == 9)
    {
        n = 40;
        m = 2;
        max_a = 999;
    }
    else if (group == 10)
    {
        n = 40;
        m = 3;
        max_a = 999;
    }
    else if (group == 11)
    {
        n = 40;
        m = 500;
        max_a = 999;
    }
    else if (group == 12)
    {
        n = 100;
        m = 2000;
        max_a = 998244353;
    }

    fout << n << " " << m << "\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            long long val = rand_int(0, max_a);
            fout << val << (j == m ? "" : " ");
        }
        fout << "\n";
    }
    fout.close();
}

// ==========================================
// CHƯƠNG TRÌNH CHÍNH
// ==========================================
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string base_dir = "TEST_CHONTAPMON";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++)
    {
        string dir_name = base_dir + "/";
        if (t < 10)
            dir_name += "0";
        dir_name += to_string(t);

        system(("mkdir -p " + dir_name).c_str());

        string inp_file = dir_name + "/D.inp";
        string out_file = dir_name + "/D.out";

        cout << "Đang sinh test " << t << " (Nhóm " << get_group(t) << ")...\n";

        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! Đã sinh 50 tests cho bài D (Chọn tập món) tại thư mục " << base_dir << " =)))\n";
    return 0;
}