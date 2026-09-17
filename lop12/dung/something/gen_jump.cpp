#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_int(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

struct Compress {
    vector<long long> vals;
    void add(long long x) { vals.push_back(x); }
    void init() {
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
    }
    int get(long long x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    }
    int size() { return vals.size(); }
};

struct SegTree {
    int n;
    vector<long long> st;
    SegTree(int n) {
        this->n = n;
        st.assign(4 * n + 7, 0);
    }
    void update(int id, int l, int r, int pos, long long val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            st[id] = max(st[id], val);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * id, l, mid, pos, val);
        update(2 * id + 1, mid + 1, r, pos, val);
        st[id] = max(st[2 * id], st[2 * id + 1]);
    }
    long long query(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return max(query(2 * id, l, mid, u, v), query(2 * id + 1, mid + 1, r, u, v));
    }
};

long long solve_jump(long long n, long long d, const vector<long long>& a) {
    Compress comp;
    for (int i = 0; i < n; i++) comp.add(a[i]);
    comp.init();

    int m = comp.size();
    SegTree st(m);
    long long ans = 0;
    vector<long long> dp(n, 0);

    for (int i = 0; i < n; i++) {
        long long mx = 0;
        auto it1 = upper_bound(comp.vals.begin(), comp.vals.end(), a[i] - d);
        if (it1 != comp.vals.begin()) {
            int id1 = it1 - comp.vals.begin();
            mx = max(mx, st.query(1, 1, m, 1, id1));
        }

        auto it2 = lower_bound(comp.vals.begin(), comp.vals.end(), a[i] + d);
        if (it2 != comp.vals.end()) {
            int id2 = it2 - comp.vals.begin() + 1;
            mx = max(mx, st.query(1, 1, m, id2, m));
        }

        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
        int id = comp.get(a[i]);
        st.update(1, 1, m, id, dp[i]);
    }
    return ans;
}

int main() {
    int num_tests = 20;
    string task_name = "jump";

    for (int i = 1; i <= num_tests; i++) {
        string folder_num = (i < 10 ? "0" : "") + to_string(i);
        string dir_path = task_name + "/" + folder_num;

        fs::create_directories(dir_path);

        string inp_name = dir_path + "/" + task_name + ".inp";
        string out_name = dir_path + "/" + task_name + ".out";

        long long n, d;
        if (i <= 5) {
            n = rand_int(10, 100);
            d = rand_int(1, 100);
        } else if (i <= 10) {
            n = rand_int(100, 1000);
            d = rand_int(10, 10000);
        } else if (i <= 15) {
            n = rand_int(1000, 10000);
            d = rand_int(100, 1000000);
        } else {
            n = rand_int(90000, 100000);
            d = rand_int(1, 1e9);
        }

        vector<long long> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = rand_int(1, 1e9);
        }

        ofstream fin(inp_name);
        fin << n << " " << d << "\n";
        for (int j = 0; j < n; j++) {
            fin << a[j] << (j == n - 1 ? "" : " ");
        }
        fin.close();

        long long ans = solve_jump(n, d, a);

        ofstream fout(out_name);
        fout << ans << "\n";
        fout.close();

        cout << "Da sinh xong test " << folder_num << " cho bai Jump!\n";
    }
    return 0;
}