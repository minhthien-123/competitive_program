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

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
struct pt
{
    long long id, sum;
    vector<long long> pre;
};

void generate_output(string inp_file, string out_file)
{
    ifstream fin(inp_file);
    ofstream fout(out_file);

    long long n, m, K;
    if (!(fin >> n >> m >> K))
        return;

    vector<vector<long long>> a(n + 1, vector<long long>(m + 1));
    vector<long long> dec;
    dec.push_back(0);
    vector<pt> inc;
    inc.push_back({0, 0, {0}});

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            fin >> a[i][j];
        }
        if (m == 1 || a[i][1] >= a[i][m])
        {
            for (int j = 1; j <= m; j++)
            {
                dec.push_back(a[i][j]);
            }
        }
        else
        {
            pt tmp;
            tmp.id = i;
            tmp.sum = 0;
            tmp.pre.assign(m + 1, 0);
            for (int j = 1; j <= m; j++)
            {
                tmp.pre[j] = tmp.pre[j - 1] + a[i][j];
                tmp.sum += a[i][j];
            }
            inc.push_back(tmp);
        }
    }

    sort(dec.begin() + 1, dec.end(), greater<long long>());
    long long dec_sz = dec.size() - 1;

    vector<long long> pre_dec(dec_sz + 1, 0);
    for (int i = 1; i <= dec_sz; i++)
    {
        pre_dec[i] = pre_dec[i - 1] + dec[i];
    }

    vector<vector<long long>> all_inc(m);
    vector<vector<long long>> pre_inc(m);

    long long inc_sz = inc.size() - 1;

    for (int rem = 0; rem < m; rem++)
    {
        all_inc[rem].push_back(0);

        for (int i = 1; i <= inc_sz; i++)
        {
            all_inc[rem].push_back(inc[i].sum);
        }

        for (int j = 1; rem + j * m <= dec_sz; j++)
        {
            long long chunk_sum = pre_dec[rem + j * m] - pre_dec[rem + (j - 1) * m];
            all_inc[rem].push_back(chunk_sum);
        }

        sort(all_inc[rem].begin() + 1, all_inc[rem].end(), greater<long long>());

        long long num = all_inc[rem].size() - 1;
        pre_inc[rem].assign(num + 1, 0);

        for (int i = 1; i <= num; i++)
        {
            pre_inc[rem][i] = pre_inc[rem][i - 1] + all_inc[rem][i];
        }
    }

    long long ans = 0;

    long long rem0 = K % m;
    if (rem0 <= dec_sz)
    {
        long long Y = K / m;
        long long num = all_inc[rem0].size() - 1;
        if (Y <= num)
        {
            ans = max(ans, pre_dec[rem0] + pre_inc[rem0][Y]);
        }
    }

    for (int i = 1; i <= inc_sz; i++)
    {
        for (int p = 1; p < m; p++)
        {
            long long C = K - p;
            if (C < 0)
                continue;

            long long rem = C % m;
            if (rem > dec_sz)
                continue;

            long long Y = C / m;
            long long num = all_inc[rem].size() - 1;

            if (Y > num - 1)
                continue;

            long long pos = lower_bound(all_inc[rem].begin() + 1, all_inc[rem].end(), inc[i].sum, greater<long long>()) - all_inc[rem].begin();

            long long sum = 0;
            if (pos <= Y)
            {
                sum = pre_inc[rem][Y + 1] - inc[i].sum;
            }
            else
            {
                sum = pre_inc[rem][Y];
            }

            long long tmp = inc[i].pre[p] + pre_dec[rem] + sum;
            ans = max(ans, tmp);
        }
    }

    fout << ans << "\n";
}

// ==========================================
// HÀM SINH INPUT THEO NHÓM
// ==========================================
void generate_input(int t, string inp_file)
{
    ofstream fout(inp_file);

    long long n, m, k;
    long long max_nm = 300000;
    long long max_val = 1000000000000LL; // 10^12

    int group = (t - 1) / 10;

    if (group == 0)
    { // Small tests
        n = rand_int(1, 50);
        m = rand_int(1, 50);
        max_val = 1000;
    }
    else if (group == 1)
    { // m = 1
        m = 1;
        n = (t == 20) ? max_nm : rand_int(max_nm / 2, max_nm);
    }
    else
    { // Mixed dimensions
        if (rand_int(0, 1))
        {
            n = rand_int(1, 500);
            m = max_nm / n;
        }
        else
        {
            m = rand_int(1, 500);
            n = max_nm / m;
        }
        if (t % 10 == 0)
        { // Test cuối mỗi cụm đánh kịch trần
            n = 1000;
            m = 300;
        }
    }

    k = rand_int(1, n * m);
    if (t % 10 == 9)
        k = n * m; // Edge case lấy sạch bánh
    if (t % 10 == 8)
        k = 1; // Edge case chỉ lấy 1 cái bánh

    fout << n << " " << m << " " << k << "\n";

    for (int i = 1; i <= n; i++)
    {
        vector<long long> row(m);
        for (int j = 0; j < m; j++)
        {
            row[j] = rand_int(1, max_val);
        }

        int type;
        if (group == 2)
            type = 0; // Luôn đơn điệu giảm
        else if (group == 3)
            type = 1; // Luôn đơn điệu tăng
        else
            type = rand_int(0, 1); // Ngẫu nhiên

        if (type == 0)
        {
            sort(row.begin(), row.end(), greater<long long>());
        }
        else
        {
            sort(row.begin(), row.end());
        }

        for (int j = 0; j < m; j++)
        {
            fout << row[j] << (j == m - 1 ? "" : " ");
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

    string base_dir = "TEST_ANBANHTHEOCHONG";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++)
    {
        string dir_name = base_dir + "/";
        if (t < 10)
            dir_name += "0";
        dir_name += to_string(t);

        system(("mkdir -p " + dir_name).c_str());

        string inp_file = dir_name + "/C.inp";
        string out_file = dir_name + "/C.out";

        cout << "Đang sinh test " << t << "...\n";

        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! Đã sinh 50 tests cho bài C tại thư mục " << base_dir << " =)))\n";
    return 0;
}