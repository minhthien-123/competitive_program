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

const int maxn = 500000;
const long long INF = 1e18;

// ==========================================
// CẤU TRÚC DỮ LIỆU CỦA NGƯỜI DÙNG (Để tạo Output)
// ==========================================
long long a_fi[maxn + 7], a_se[maxn + 7];
long long s_fi[maxn + 7], s_se[maxn + 7];
pair<long long, long long> s_arr[maxn + 7];
long long min_cost[maxn + 7];
long long dp[maxn + 7];
long long pre[maxn + 7];

struct node
{
    long long mx, dp_max, dp_min, lz, max_val;
} st[4 * maxn + 7];

void del_node(int id)
{
    st[id].mx = -INF;
    st[id].dp_max = -INF;
    st[id].dp_min = INF;
    st[id].max_val = -INF;
    st[id].lz = -1;
}

void apply(int id, long long cost)
{
    if (st[id].dp_max == -INF)
        return;
    st[id].lz = cost;
    st[id].max_val = st[id].mx - cost;
}

node merge_nodes(node l, node r)
{
    node res;
    res.mx = max(l.mx, r.mx);
    res.dp_max = max(l.dp_max, r.dp_max);
    res.dp_min = min(l.dp_min, r.dp_min);
    res.max_val = max(l.max_val, r.max_val);
    res.lz = -1;
    return res;
}

void down(int id)
{
    if (st[id].lz != -1)
    {
        apply(id * 2, st[id].lz);
        apply(id * 2 + 1, st[id].lz);
        st[id].lz = -1;
    }
}

void build(int id, int l, int r)
{
    del_node(id);
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}

void add_node(int id, int l, int r, int pos, long long dp_val, long long val)
{
    if (l == r)
    {
        st[id].mx = val;
        st[id].dp_max = dp_val;
        st[id].dp_min = dp_val;
        st[id].lz = -1;
        st[id].max_val = val;
        return;
    }
    down(id);
    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        add_node(id * 2, l, mid, pos, dp_val, val);
    }
    else
    {
        add_node(id * 2 + 1, mid + 1, r, pos, dp_val, val);
    }
    st[id] = merge_nodes(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int u, int v, long long cost)
{
    if (v < l || r < u || st[id].dp_max == -INF)
        return;
    if (u <= l && r <= v)
    {
        if (cost <= st[id].dp_min)
        {
            apply(id, cost);
            return;
        }
        if (cost > st[id].dp_max)
        {
            del_node(id);
            return;
        }
    }
    down(id);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, cost);
    update(id * 2 + 1, mid + 1, r, u, v, cost);
    st[id] = merge_nodes(st[id * 2], st[id * 2 + 1]);
}

long long query(int id, int l, int r, int u, int v)
{
    if (v < l || r < u || st[id].dp_max == -INF)
        return -INF;
    if (u <= l && r <= v)
        return st[id].max_val;
    down(id);
    int mid = (l + r) / 2;
    long long get1 = query(id * 2, l, mid, u, v);
    long long get2 = query(id * 2 + 1, mid + 1, r, u, v);
    return max(get1, get2);
}

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
void generate_output(string inp_file, string out_file)
{
    ifstream fin(inp_file);
    ofstream fout(out_file);

    int n, m, k;
    long long x;
    if (!(fin >> n >> m >> k >> x))
        return;

    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        fin >> a_fi[i] >> a_se[i];
        pre[i] = pre[i - 1] + a_se[i];
    }
    for (int i = 1; i <= m; i++)
    {
        fin >> s_arr[i].first >> s_arr[i].second;
    }
    sort(s_arr + 1, s_arr + m + 1);

    min_cost[m + 1] = INF;
    for (int j = m; j >= 1; j--)
    {
        min_cost[j] = min(min_cost[j + 1], s_arr[j].second);
    }

    build(1, 1, n);
    dp[0] = x;
    vector<int> st_stack;

    for (int i = 1; i <= n; i++)
    {
        if (dp[i - 1] != -1)
        {
            add_node(1, 0, n, i - 1, dp[i - 1], dp[i - 1] - pre[i - 1]);
        }

        while (!st_stack.empty() && a_fi[st_stack.back()] <= a_fi[i])
        {
            st_stack.pop_back();
        }

        int L = st_stack.empty() ? 0 : st_stack.back();

        int pos = m + 1;
        int l = 1, r = m;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (s_arr[mid].first >= a_fi[i])
            {
                pos = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        long long cost_i = min_cost[pos];

        update(1, 0, n, L, i - 1, cost_i);
        st_stack.push_back(i);

        long long best = query(1, 0, n, max(0, i - k), i - 1);

        if (best == -INF)
        {
            dp[i] = -1;
        }
        else
        {
            dp[i] = best + pre[i];
        }
    }

    if (dp[n] != -1)
    {
        fout << "Yes\n";
    }
    else
    {
        fout << "No\n";
    }
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
    if (t <= 21)
        return 4;
    if (t <= 26)
        return 5;
    if (t <= 31)
        return 6;
    if (t <= 37)
        return 7;
    if (t <= 43)
        return 8;
    return 9;
}

void generate_input(int t, string inp_file)
{
    ofstream fout(inp_file);
    int sub = get_subtask(t);

    long long n = 1, m = 1, k = 1, x = 1;
    long long max_val = 1e9;

    if (sub == 1)
    {
        n = rand_int(1, 500000);
        m = rand_int(1, 500000);
        k = 1;
    }
    else if (sub == 2)
    {
        n = rand_int(1, 100);
        m = rand_int(1, 100);
        k = n;
    }
    else if (sub == 3)
    {
        n = rand_int(1, 100000);
        m = rand_int(1, 3000);
        k = n;
    }
    else if (sub == 4)
    {
        n = rand_int(1, 500000);
        m = rand_int(1, 500000);
        k = n;
    }
    else if (sub == 5)
    {
        n = rand_int(1, 400);
        m = rand_int(1, 400);
        k = rand_int(1, n);
    }
    else if (sub == 6)
    {
        n = rand_int(1, 3000);
        m = rand_int(1, 3000);
        k = rand_int(1, n);
    }
    else if (sub == 7)
    {
        n = rand_int(1, 150000);
        m = rand_int(1, 150000);
        k = rand_int(1, n);
    }
    else if (sub == 8)
    {
        n = rand_int(1, 300000);
        m = rand_int(1, 300000);
        k = rand_int(1, n);
    }
    else if (sub == 9)
    {
        n = rand_int(1, 500000);
        m = rand_int(1, 500000);
        k = rand_int(1, n);
    }

    // Test tối đa kịch trần cho mỗi subtask
    if (t == 5)
    {
        n = 500000;
        m = 500000;
        k = 1;
    }
    if (t == 10)
    {
        n = 100;
        m = 100;
        k = n;
    }
    if (t == 15)
    {
        n = 100000;
        m = 3000;
        k = n;
    }
    if (t == 21)
    {
        n = 500000;
        m = 500000;
        k = n;
    }
    if (t == 26)
    {
        n = 400;
        m = 400;
    }
    if (t == 31)
    {
        n = 3000;
        m = 3000;
    }
    if (t == 37)
    {
        n = 150000;
        m = 150000;
    }
    if (t == 43)
    {
        n = 300000;
        m = 300000;
    }
    if (t >= 48)
    {
        n = 500000;
        m = 500000;
    }

    x = rand_int(1000, max_val / 2); // Khởi điểm có một chút tài nguyên

    fout << n << " " << m << " " << k << " " << x << "\n";

    long long max_h = 1000000; // Tránh sinh quá to dẫn tới No liên tục
    for (int i = 1; i <= n; i++)
    {
        long long h = rand_int(1, max_h);
        long long r = rand_int(1, max_val / 100);
        fout << h << " " << r << "\n";
    }

    for (int i = 1; i <= m; i++)
    {
        long long s = rand_int(max_h / 2, max_h * 2); // Tool có sức mạnh bao quát mục tiêu
        long long c = rand_int(1, x);                 // Giá tool nhẹ nhẹ để dễ mua
        fout << s << " " << c << "\n";
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

    string base_dir = "TEST_CONGCUHUUHAN";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++)
    {
        string dir_name = base_dir + "/";
        if (t < 10)
            dir_name += "0";
        dir_name += to_string(t);

        system(("mkdir -p " + dir_name).c_str());

        string inp_file = dir_name + "/I.inp";
        string out_file = dir_name + "/I.out";

        cout << "Đang sinh test " << t << " (Subtask " << get_subtask(t) << ")...\n";

        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! Bộ 50 tests cho bài I đã nằm gọn trong " << base_dir << " rồi nha bác =)))\n";
    return 0;
}