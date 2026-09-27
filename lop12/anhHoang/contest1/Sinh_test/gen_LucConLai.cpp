#include <bits/stdc++.h>

using namespace std;

// ==========================================
// CẤU HÌNH VÀ HÀM RANDOM
// ==========================================
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_int(long long l, long long r) {
    if (l > r) swap(l, r);
    return uniform_int_distribution<long long>(l, r)(rng);
}

const int maxn = 300000;

// ==========================================
// CẤU TRÚC DỮ LIỆU CỦA NGƯỜI DÙNG (Để tạo Output)
// ==========================================
long long a_arr[maxn + 5];

struct pt {
    int l, id;
    long long d;
};
vector<pt> queries[maxn + 5];
long long ans_arr[maxn + 5];
long long st[4 * maxn + 5], lz_set[4 * maxn + 5], lz_add[4 * maxn + 5];
int n_global, q_global;

void build(int id, int l, int r) {
    lz_set[id] = -1;
    lz_add[id] = 0;
    st[id] = 0;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}

void down(int id) {
    if (lz_set[id] != -1) {
        st[id * 2] = lz_set[id];
        lz_set[id * 2] = lz_set[id];
        lz_add[id * 2] = 0;

        st[id * 2 + 1] = lz_set[id];
        lz_set[id * 2 + 1] = lz_set[id];
        lz_add[id * 2 + 1] = 0;

        lz_set[id] = -1;
    }
    if (lz_add[id] != 0) {
        st[id * 2] += lz_add[id];
        if (lz_set[id * 2] == -1) lz_add[id * 2] += lz_add[id];
        else lz_set[id * 2] += lz_add[id];

        st[id * 2 + 1] += lz_add[id];
        if (lz_set[id * 2 + 1] == -1) lz_add[id * 2 + 1] += lz_add[id];
        else lz_set[id * 2 + 1] += lz_add[id];

        lz_add[id] = 0;
    }
}

void update_set(int id, int l, int r, int u, int v, long long val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        st[id] = val;
        lz_set[id] = val;
        lz_add[id] = 0;
        return;
    }
    down(id);
    int mid = (l + r) / 2;
    update_set(id * 2, l, mid, u, v, val);
    update_set(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void update_add(int id, int l, int r, int u, int v, long long val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        st[id] += val;
        if (lz_set[id] == -1) lz_add[id] += val;
        else lz_set[id] += val;
        return;
    }
    down(id);
    int mid = (l + r) / 2;
    update_add(id * 2, l, mid, u, v, val);
    update_add(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int walk(int id, int l, int r, long long val) {
    if (st[id] < val) return n_global + 1;
    if (l == r) return l;
    down(id);
    int mid = (l + r) / 2;
    if (st[id * 2] >= val) return walk(id * 2, l, mid, val);
    return walk(id * 2 + 1, mid + 1, r, val);
}

long long query(int id, int l, int r, int pos) {
    if (l == r) return st[id];
    down(id);
    int mid = (l + r) / 2;
    if (pos <= mid) return query(id * 2, l, mid, pos);
    return query(id * 2 + 1, mid + 1, r, pos);
}

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
void generate_output(string inp_file, string out_file) {
    ifstream fin(inp_file);
    ofstream fout(out_file);

    if (!(fin >> n_global >> q_global)) return;

    // Clear mảng queries cho mỗi test mới
    for (int i = 0; i <= n_global; i++) {
        queries[i].clear();
    }

    for (int i = 1; i <= n_global; i++) {
        fin >> a_arr[i];
    }

    if (n_global <= 10000 && q_global <= 10000) {
        for (int i = 1; i <= q_global; i++) {
            int l, r;
            long long d;
            fin >> l >> r >> d;

            long long ans = d;
            for (int j = l; j <= r; j++) {
                if (ans >= a_arr[j]) {
                    ans = max(a_arr[j] - 1, ans - a_arr[j]);
                }
            }
            fout << ans << "\n";
        }
    } else {
        build(1, 1, n_global);

        long long M = 0;
        for (int i = 1; i <= q_global; i++) {
            int l, r;
            long long d;
            fin >> l >> r >> d;
            M = d;
            queries[r].push_back({l, i, d});
        }
        
        for (int i = 1; i <= n_global; i++) {
            update_set(1, 1, n_global, i, i, M);

            int pos1 = walk(1, 1, n_global, a_arr[i]);
            int pos2 = walk(1, 1, n_global, 2 * a_arr[i]);

            if (pos1 <= i) {
                int R = min(pos2 - 1, i);
                if (pos1 <= R) {
                    update_set(1, 1, n_global, pos1, R, a_arr[i] - 1);
                }
            }
            if (pos2 <= i) {
                update_add(1, 1, n_global, pos2, i, -a_arr[i]);
            }

            for (auto q_item : queries[i]) {
                ans_arr[q_item.id] = query(1, 1, n_global, q_item.l);
            }
        }

        for (int i = 1; i <= q_global; i++) {
            fout << ans_arr[i] << "\n";
        }
    }
}

// ==========================================
// HÀM XÁC ĐỊNH NHÓM TEST VÀ SINH INPUT
// ==========================================
int get_subtask(int t) {
    if (t <= 5) return 1;
    if (t <= 10) return 2;
    if (t <= 17) return 3;
    if (t <= 25) return 4;
    if (t <= 32) return 5;
    if (t <= 41) return 6;
    return 7;
}

void generate_input(int t, string inp_file) {
    ofstream fout(inp_file);
    int sub = get_subtask(t);

    long long n, q, max_d, max_a = 1000000000;
    bool same_d = false;

    if (sub == 1) {
        n = rand_int(5, 10); q = rand_int(5, 10); max_d = 10; max_a = 10;
    } else if (sub == 2) {
        n = rand_int(100, 500); q = rand_int(100, 500); max_d = 500; max_a = 500;
    } else if (sub == 3) {
        n = rand_int(500, 1000); q = rand_int(500, 1000); max_d = 1000000000;
    } else if (sub == 4) {
        n = rand_int(5000, 10000); q = rand_int(5000, 10000); max_d = 1000000000; same_d = true;
    } else if (sub == 5) {
        n = rand_int(5000, 10000); q = rand_int(5000, 10000); max_d = 1000000000;
    } else if (sub == 6) {
        n = rand_int(100000, 300000); q = rand_int(100000, 300000); max_d = 1000000000; same_d = true;
    } else {
        n = rand_int(100000, 300000); q = rand_int(100000, 300000); max_d = 1000000000;
    }

    // Các test cuối subtask sẽ ép kịch trần
    if (t == 5) { n = 10; q = 10; max_d = 10; }
    if (t == 10) { n = 500; q = 500; max_d = 500; }
    if (t == 17) { n = 1000; q = 1000; }
    if (t == 25 || t == 32) { n = 10000; q = 10000; }
    if (t == 41 || t == 50) { n = 300000; q = 300000; }

    fout << n << " " << q << "\n";
    for (int i = 1; i <= n; i++) {
        fout << rand_int(0, max_a) << (i == n ? "" : " ");
    }
    fout << "\n";

    long long fixed_d = rand_int(1, max_d);
    for (int i = 1; i <= q; i++) {
        int l = rand_int(1, n);
        int r = rand_int(1, n);
        if (l > r) swap(l, r);
        long long d = same_d ? fixed_d : rand_int(1, max_d);
        fout << l << " " << r << " " << d << "\n";
    }
    fout.close();
}

// ==========================================
// CHƯƠNG TRÌNH CHÍNH
// ==========================================
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string base_dir = "TEST_LUCCONLAI";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++) {
        string dir_name = base_dir + "/";
        if (t < 10) dir_name += "0";
        dir_name += to_string(t);

        system(("mkdir -p " + dir_name).c_str());

        string inp_file = dir_name + "/J.inp";
        string out_file = dir_name + "/J.out";

        cout << "Đang sinh test " << t << " (Subtask " << get_subtask(t) << ")...\n";
        
        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! 50 tests cho bài J đã phủ kín thư mục " << base_dir << " :)))\n";
    return 0;
}