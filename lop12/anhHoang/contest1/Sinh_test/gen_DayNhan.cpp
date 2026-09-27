#include <bits/stdc++.h>

using namespace std;

// ==========================================
// CẤU HÌNH VÀ HÀM RANDOM
// ==========================================
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_int(long long l, long long r)
{
    if (l > r)
        swap(l, r);
    return uniform_int_distribution<long long>(l, r)(rng);
}

const int mod = 1e9 + 7;
long long add(long long x, long long y) { return (x + y + 2 * mod) % mod; }
long long mul(long long x, long long y) { return (x % mod * (y % mod)) % mod; }

// ==========================================
// CẤU TRÚC DỮ LIỆU CỦA NGƯỜI DÙNG (Để tạo Output)
// ==========================================
struct Combinatorics
{
    int n;
    long long MOD;
    vector<long long> fact, inv_fact, inverse;

    Combinatorics(int n, long long MOD) : n(n), MOD(MOD)
    {
        fact.assign(n + 1, 1);
        inv_fact.assign(n + 1, 1);
        inverse.assign(n + 1, 1);

        for (int i = 2; i <= n; i++)
        {
            inverse[i] = MOD - (MOD / i) * inverse[MOD % i] % MOD;
        }

        for (int i = 2; i <= n; i++)
        {
            fact[i] = (fact[i - 1] * i) % MOD;
            inv_fact[i] = (inv_fact[i - 1] * inverse[i]) % MOD;
        }
    }
};

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
void generate_output(string inp_file, string out_file)
{
    ifstream fin(inp_file);
    ofstream fout(out_file);

    int n;
    long long m;
    if (!(fin >> n >> m))
        return;

    Combinatorics comb(n + 1, mod);

    int S = 0;
    int C = 1;

    for (int k = 0; k <= n - 1; k++)
    {
        int term = mul(C, comb.inverse[n - k + 1]);
        S = add(S, term);

        int num = (m - n + k + 1) % mod;
        int den = comb.inverse[k + 1];
        C = mul(C, mul(num, den));
    }

    S = mul(S, comb.fact[n + 1]);
    fout << S << "\n";
}

// ==========================================
// HÀM XÁC ĐỊNH NHÓM TEST VÀ SINH INPUT
// ==========================================
int get_subtask(int t)
{
    if (t <= 5)
        return 1;
    if (t <= 10)
        return 2;
    if (t <= 15)
        return 3;
    if (t <= 20)
        return 4;
    if (t <= 25)
        return 5;
    if (t <= 30)
        return 6;
    if (t <= 36)
        return 7;
    if (t <= 42)
        return 8;
    return 9;
}

void generate_input(int t, string inp_file)
{
    ofstream fout(inp_file);
    int sub = get_subtask(t);

    long long n = 1, m = 1;

    if (sub == 1)
    { // m <= 8
        m = (t == 5) ? 8 : rand_int(1, 8);
        n = rand_int(1, m);
    }
    else if (sub == 2)
    { // m <= 20
        m = (t == 10) ? 20 : rand_int(9, 20);
        n = rand_int(1, m);
    }
    else if (sub == 3)
    { // m <= 300
        m = (t == 15) ? 300 : rand_int(21, 300);
        n = rand_int(1, m);
    }
    else if (sub == 4)
    { // n <= 300
        n = (t == 20) ? 300 : rand_int(1, 300);
        m = rand_int(max(301LL, n), 1000000000LL); // m có thể lớn đến 10^9
    }
    else if (sub == 5)
    { // m <= 2000
        m = (t == 25) ? 2000 : rand_int(301, 2000);
        n = rand_int(1, m);
    }
    else if (sub == 6)
    { // n <= 2000
        n = (t == 30) ? 2000 : rand_int(301, 2000);
        m = rand_int(max(2001LL, n), 1000000000LL);
    }
    else if (sub == 7)
    { // n = m
        n = m = (t == 36) ? 1000000 : rand_int(2001, 1000000);
    }
    else if (sub == 8)
    { // m <= 10^6
        m = (t == 42) ? 1000000 : rand_int(2001, 1000000);
        n = rand_int(1, m);
    }
    else if (sub == 9)
    { // Không ràng buộc thêm
        n = (t >= 48) ? 1000000 : rand_int(2001, 1000000);
        m = (t == 50) ? 1000000000LL : rand_int(max(n, 1000001LL), 1000000000LL);
    }

    fout << n << " " << m << "\n";
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

    string base_dir = "TEST_DAYNHAN";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++)
    {
        string dir_name = base_dir + "/";
        if (t < 10)
            dir_name += "0";
        dir_name += to_string(t);

        system(("mkdir -p " + dir_name).c_str());

        string inp_file = dir_name + "/H.inp";
        string out_file = dir_name + "/H.out";

        cout << "Đang sinh test " << t << " (Subtask " << get_subtask(t) << ")...\n";

        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! Bộ 50 tests cho bài H đã sẵn sàng tại " << base_dir << " =)))\n";
    return 0;
}