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

const int maxn = 2e5;
const int maxv = 1e7;

// ==========================================
// CẤU TRÚC DỮ LIỆU CỦA NGƯỜI DÙNG (Để tạo Output)
// ==========================================
struct Sieve
{
    int n;
    vector<int> min_prime;
    vector<int> primes;
    vector<int> prime_idx;

    Sieve(int n) : n(n)
    {
        min_prime.assign(n + 1, 0);
        prime_idx.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            if (min_prime[i] == 0)
            {
                min_prime[i] = i;
                prime_idx[i] = primes.size();
                primes.push_back(i);
            }
            for (int p : primes)
            {
                if (p > min_prime[i] || i * p > n)
                {
                    break;
                }
                min_prime[i * p] = p;
            }
        }
    }
};

Sieve sieve(maxv); // Khởi tạo sàng 1 lần duy nhất cho nhanh

struct Node
{
    int lc, rc;
    int mn;
} st[maxn * 180];

int roots[maxn + 7];
int node_cnt = 0;
int a[maxn + 7];
int n, q;

int build(int l, int r)
{
    node_cnt++;
    int id = node_cnt;
    if (l == r)
    {
        st[id].mn = 0;
        return id;
    }
    int mid = (l + r) / 2;
    st[id].lc = build(l, mid);
    st[id].rc = build(mid + 1, r);
    st[id].mn = 0;
    return id;
}

int update(int old_id, int l, int r, int pos, int val)
{
    node_cnt++;
    int id = node_cnt;
    st[id] = st[old_id];

    if (l == r)
    {
        st[id].mn = val;
        return id;
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        st[id].lc = update(st[old_id].lc, l, mid, pos, val);
    }
    else
    {
        st[id].rc = update(st[old_id].rc, mid + 1, r, pos, val);
    }
    st[id].mn = min(st[st[id].lc].mn, st[st[id].rc].mn);
    return id;
}

int query(int id, int l, int r, int val)
{
    if (l == r)
        return l;

    int mid = (l + r) / 2;
    if (st[st[id].lc].mn < val)
    {
        return query(st[id].lc, l, mid, val);
    }
    else
    {
        return query(st[id].rc, mid + 1, r, val);
    }
}

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
void generate_output(string inp_file, string out_file)
{
    ifstream fin(inp_file);
    ofstream fout(out_file);

    node_cnt = 0; // RESET tree size cho mỗi test

    fin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }

    int m = sieve.primes.size();
    roots[0] = build(0, m - 1);
    for (int i = 1; i <= n; i++)
    {
        int tmp = a[i];
        int cur_root = roots[i - 1];
        while (tmp > 1)
        {
            int p = sieve.min_prime[tmp];
            cur_root = update(cur_root, 0, m - 1, sieve.prime_idx[p], i);
            while (tmp % p == 0)
            {
                tmp /= p;
            }
        }
        roots[i] = cur_root;
    }

    while (q--)
    {
        int l, r;
        fin >> l >> r;
        int ans = query(roots[r], 0, m - 1, l);
        fout << sieve.primes[ans] << "\n";
    }
}

// ==========================================
// HÀM SINH INPUT THEO TỪNG SUBTASK
// ==========================================
int get_subtask(int t)
{
    return (t - 1) / 5 + 1; // Mỗi subtask 5 test
}

void generate_input(int t, string inp_file)
{
    ofstream fout(inp_file);
    int sub = get_subtask(t);

    int n_max = 200000, q_max = 200000, a_max = 10000000;
    bool l_eq_r = false;
    bool prime_only = false;

    // Phân bổ giới hạn theo subtask
    if (sub == 1)
    {
        n_max = 50;
        q_max = 50;
        a_max = 100;
    }
    else if (sub == 2)
    {
        n_max = 2000;
        q_max = 2000;
        a_max = 500;
    }
    else if (sub == 3)
    {
        a_max = 3;
    }
    else if (sub == 4)
    {
        l_eq_r = true;
        a_max = 100000;
    }
    else if (sub == 5)
    {
        l_eq_r = true;
    }
    else if (sub == 6)
    {
        prime_only = true;
    }
    else if (sub == 7)
    {
        n_max = 20000;
        q_max = 20000;
    }
    else if (sub == 8)
    {
        n_max = 100000;
        q_max = 20000;
    }
    else if (sub == 9)
    {
        n_max = 80000;
        q_max = 80000;
    }
    // sub 10 giữ nguyên max không có ràng buộc thêm

    // Test đầu tiên của mỗi subtask (t % 5 == 1) sẽ sinh cực đại giới hạn để test time limit
    int cur_n = (t % 5 == 1) ? n_max : rand_int(max(1.0, n_max * 0.8), n_max);
    int cur_q = (t % 5 == 1) ? q_max : rand_int(max(1.0, q_max * 0.8), q_max);

    fout << cur_n << " " << cur_q << "\n";

    for (int i = 1; i <= cur_n; i++)
    {
        if (prime_only)
        {
            // Lấy ngẫu nhiên một số nguyên tố
            fout << sieve.primes[rand_int(0, sieve.primes.size() - 1)] << (i == cur_n ? "" : " ");
        }
        else
        {
            fout << rand_int(1, a_max) << (i == cur_n ? "" : " ");
        }
    }
    fout << "\n";

    for (int i = 1; i <= cur_q; i++)
    {
        if (l_eq_r)
        {
            int pos = rand_int(1, cur_n);
            fout << pos << " " << pos << "\n";
        }
        else
        {
            int l = rand_int(1, cur_n);
            int r = rand_int(1, cur_n);
            if (l > r)
                swap(l, r);
            fout << l << " " << r << "\n";
        }
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

    string base_dir = "TEST_SANMAKICHHOAT";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++)
    {
        // Tạo chuỗi thư mục 01, 02 ... 50
        string dir_name = base_dir + "/";
        if (t < 10)
            dir_name += "0";
        dir_name += to_string(t);

        // Tạo folder bằng bash command trên Linux
        string cmd = "mkdir -p " + dir_name;
        system(cmd.c_str());

        string inp_file = dir_name + "/A.inp";
        string out_file = dir_name + "/A.out";

        cout << "Đang sinh test " << t << " (Subtask " << get_subtask(t) << ")...\n";

        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! Đã sinh thành công " << total_tests << " tests tại thư mục " << base_dir << "!\n";
    return 0;
}