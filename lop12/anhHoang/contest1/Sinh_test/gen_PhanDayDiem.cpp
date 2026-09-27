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

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
void generate_output(string inp_file, string out_file) {
    ifstream fin(inp_file);
    ofstream fout(out_file);

    int n, k;
    if (!(fin >> n >> k)) return;

    // Cấp phát dư 2 phần tử n+2 để tránh lỗi truy cập a[i+1] khi i=n
    vector<vector<long long>> a(n + 2, vector<long long>(k, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            fin >> a[i][j];
        }
    }

    auto getV = [&](int id, int mask) -> long long {
        long long res = 0;
        for (int c = 0; c < k; c++) {
            if ((mask >> c) & 1) {
                res += a[id][c];
            } else {
                res -= a[id][c];
            }
        }
        return res;
    };

    vector<long long> dp(n + 1, 0);
    vector<long long> best(1 << k, 0);

    for (int mask = 0; mask < (1 << k); mask++) {
        best[mask] = -getV(1, mask);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int mask = 0; mask < (1 << k); mask++) {
            dp[i] = max(dp[i], getV(i, mask) + best[mask]);
        }

        for (int mask = 0; mask < (1 << k); mask++) {
            best[mask] = max(best[mask], dp[i] - getV(i + 1, mask));
        }
    }

    fout << dp[n] << "\n";
}

// ==========================================
// HÀM XÁC ĐỊNH NHÓM TEST VÀ SINH INPUT
// ==========================================
int get_subtask(int t) {
    if (t <= 12) return 1;
    if (t <= 25) return 2;
    if (t <= 37) return 3;
    return 4;
}

void generate_input(int t, string inp_file) {
    ofstream fout(inp_file);
    int sub = get_subtask(t);

    long long n, k, max_a = 1000000000;

    // Phân bổ n, k, max_a dựa vào ràng buộc subtask
    if (sub == 1) {
        max_a = 1;
        n = (t <= 3) ? rand_int(1, 100) : rand_int(90000, 100000);
        k = rand_int(1, 10);
    } else if (sub == 2) {
        k = 1;
        n = (t <= 16) ? rand_int(1, 1000) : rand_int(90000, 100000);
    } else if (sub == 3) {
        n = (t <= 30) ? rand_int(1, 100) : rand_int(2500, 3000);
        k = rand_int(1, 10);
    } else {
        n = (t <= 42) ? rand_int(1, 1000) : rand_int(90000, 100000);
        k = rand_int(1, 10);
    }
    
    // Gán max test vào những test cuối của mỗi subtask
    if (t == 12) { n = 100000; k = 10; }
    if (t == 25) { n = 100000; k = 1; }
    if (t == 37) { n = 3000; k = 10; }
    if (t >= 48) { n = 100000; k = 10; }

    fout << n << " " << k << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            fout << rand_int(0, max_a) << (j == k ? "" : " ");
        }
        fout << "\n";
    }
    fout.close();
}

// ==========================================
// CHƯƠNG TRÌNH CHÍNH
// ==========================================
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string base_dir = "TEST_PHANDAYDIEM";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++) {
        string dir_name = base_dir + "/";
        if (t < 10) dir_name += "0";
        dir_name += to_string(t);

        system(("mkdir -p " + dir_name).c_str());

        string inp_file = dir_name + "/G.inp";
        string out_file = dir_name + "/G.out";

        cout << "Đang sinh test " << t << " (Subtask " << get_subtask(t) << ")...\n";
        
        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! Đã sinh thành công 50 tests cho bài G tại thư mục " << base_dir << " :)))\n";
    return 0;
}