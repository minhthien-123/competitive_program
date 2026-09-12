#include <bits/stdc++.h>
#include <sys/stat.h>

using namespace std;

// Sử dụng mt19937_64 theo đúng yêu cầu
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rand_int(long long l, long long r)
{
    return uniform_int_distribution<long long>(l, r)(rng);
}

const long long INF = 1e18;

// Segment Tree hỗ trợ Range Add và Range Max
struct SegTree
{
    int n;
    vector<long long> tree, lazy;
    SegTree(int n) : n(n), tree(4 * n + 5, -INF), lazy(4 * n + 5, 0) {}

    void push(int node)
    {
        if (lazy[node] != 0)
        {
            tree[2 * node] += lazy[node];
            lazy[2 * node] += lazy[node];
            tree[2 * node + 1] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int u, int v, long long val)
    {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v)
        {
            tree[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, u, v, val);
        update(2 * node + 1, mid + 1, r, u, v, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void set_val(int node, int l, int r, int pos, long long val)
    {
        if (l == r)
        {
            tree[node] = val;
            lazy[node] = 0;
            return;
        }
        push(node);
        int mid = l + (r - l) / 2;
        if (pos <= mid)
            set_val(2 * node, l, mid, pos, val);
        else
            set_val(2 * node + 1, mid + 1, r, pos, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int node, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return -INF;
        if (u <= l && r <= v)
            return tree[node];
        push(node);
        int mid = l + (r - l) / 2;
        return max(query(2 * node, l, mid, u, v), query(2 * node + 1, mid + 1, r, u, v));
    }
};

// Thuật toán giải bài toán chuẩn O(N log N) để sinh output
long long solve(int n, const vector<long long> &a)
{
    vector<long long> dp(n + 1, 0);
    SegTree st(n);
    vector<int> st_idx;
    st_idx.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        st.set_val(1, 1, n, i, dp[i - 1] - a[i]);

        while (st_idx.size() > 1 && a[st_idx.back()] > a[i])
        {
            int top_idx = st_idx.back();
            st_idx.pop_back();
            int prev_idx = st_idx.back();
            st.update(1, 1, n, prev_idx + 1, top_idx, a[i] - a[top_idx]);
        }
        st.update(1, 1, n, i, i, a[i]);
        st_idx.push_back(i);

        dp[i] = a[i] + st.query(1, 1, n, 1, i);
    }
    return dp[n];
}

void build_test(int test_id)
{
    int n;
    // Phân bổ N theo đúng Subtask trong đề bài
    if (test_id <= 12)
    {
        n = (test_id == 12) ? 200 : rand_int(190, 200); // 40%
    }
    else if (test_id <= 21)
    {
        n = (test_id == 21) ? 5000 : rand_int(4900, 5000); // 30%
    }
    else
    {
        n = (test_id == 30) ? 100000 : rand_int(99000, 100000); // 30%
    }

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        // Trộn các loại test: số nhỏ, số dương lớn, hoặc full dải âm dương
        if (test_id % 3 == 0)
            a[i] = rand_int(-100, 100);
        else if (test_id % 3 == 1)
            a[i] = rand_int(1, 1e9);
        else
            a[i] = rand_int(-1e9, 1e9);
    }

    // Tạo thư mục (Sử dụng lệnh hệ thống cực tiện trên Linux)
    char dir_name[100];
    sprintf(dir_name, "test_energy/%02d", test_id);
    string cmd = "mkdir -p " + string(dir_name);
    system(cmd.c_str());

    // Ghi file input
    string inp_file = string(dir_name) + "/energy.inp";
    ofstream fo_inp(inp_file);
    fo_inp << n << "\n";
    for (int i = 1; i <= n; i++)
    {
        fo_inp << a[i] << (i == n ? "" : " ");
    }
    fo_inp.close();

    // Chạy giải thuật và ghi file output
    long long ans = solve(n, a);
    string out_file = string(dir_name) + "/energy.out";
    ofstream fo_out(out_file);
    fo_out << ans << "\n";
    fo_out.close();

    cout << "Da sinh xong Test " << setfill('0') << setw(2) << test_id
         << " | N = " << n << " | Ans = " << ans << "\n";
}

int main()
{
    // Tạo folder gốc
    system("mkdir -p test_energy");
    cout << "Bat dau sinh 30 test...\n";

    for (int i = 1; i <= 30; i++)
    {
        build_test(i);
    }

    cout << "Hoan thanh! :)))\n";
    return 0;
}