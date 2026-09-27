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

const int maxn = 2e5;
const int bl = 450;
const int max_q = 4e5;

// ==========================================
// CẤU TRÚC DỮ LIỆU CỦA NGƯỜI DÙNG (Để tạo Output)
// ==========================================
long long sum_light[bl + 5][2 * bl + 5];

struct FenwickTree {
    vector<long long> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 7, 0);
    }
    
    void reset() {
        fill(bit.begin(), bit.end(), 0);
    }

    long long sum(int r) {
        long long res = 0;
        for (; r > 0; r -= r & -r) {
            res += bit[r];
        }
        return res;
    }

    void add(int idx, long long delta) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }
};

FenwickTree ft(maxn + 5);

void update_light(int x, int k, int sign) {
    long long val = 1LL * x * sign;
    for (int rem = 1; rem <= k; rem++) {
        sum_light[k][rem] += val;
    }
}

void update_heavy(int x, int k, int sign) {
    long long val = 1LL * x * sign;
    for (int i = 0;; i++) {
        int L = i * 2 * k + 1;
        int R = i * 2 * k + k;
        if (L > maxn) break;
        R = min(R, maxn);
        ft.add(L, val);
        ft.add(R + 1, -val);
    }
}

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
void generate_output(string inp_file, string out_file) {
    ifstream fin(inp_file);
    ofstream fout(out_file);
    
    // Reset toàn bộ trạng thái mảng toàn cục cho test mới
    ft.reset();
    memset(sum_light, 0, sizeof(sum_light));

    int q;
    if (!(fin >> q)) return;

    while (q--) {
        string type;
        fin >> type;

        if (type == "ADD" || type == "DEL") {
            int x, k;
            fin >> x >> k;
            int sign = (type == "ADD" ? 1 : -1);

            if (k <= bl) {
                update_light(x, k, sign);
            } else {
                update_heavy(x, k, sign);
            }
        } else if (type == "ASK") {
            int t;
            fin >> t;

            long long ans = ft.sum(t);

            for (int k = 1; k <= bl; k++) {
                int rem = (t - 1) % (2 * k) + 1;
                ans += sum_light[k][rem];
            }
            fout << ans << "\n";
        }
    }
}

// ==========================================
// HÀM SINH INPUT THEO NHÓM
// ==========================================
void generate_input(int test_num, string inp_file) {
    ofstream fout(inp_file);
    int group = (test_num - 1) / 10 + 1;
    
    int q_queries = max_q;
    int max_k = 200000;
    int max_t = 200000;
    
    // Lưu các chiến dịch đang tồn tại để đảm bảo truy vấn DEL hợp lệ
    vector<pair<int, int>> active_pool;

    if (group == 1) { 
        q_queries = 1000; max_k = 1000; max_t = 1000; 
    } else if (group == 2) { 
        q_queries = 50000; 
    } else if (group == 3) { 
        q_queries = 50000; 
    } else if (group == 4) { 
        q_queries = 100000; 
    } else if (group == 5) { 
        q_queries = (test_num == 50) ? max_q : rand_int(max_q * 0.8, max_q); 
    }

    fout << q_queries << "\n";

    for (int i = 1; i <= q_queries; i++) {
        int op_type = rand_int(1, 100);
        
        // Điều hướng xác suất tùy theo từng nhóm test
        if (group == 2) {
            // Group 2: Tập trung test k nhỏ (light updates), chỉ ADD và ASK
            op_type = rand_int(1, 2) == 1 ? 10 : 80; // Tránh DEL
        } else if (group == 3) {
            // Group 3: Tập trung test k lớn (heavy updates), chỉ ADD và ASK
            op_type = rand_int(1, 2) == 1 ? 10 : 80; // Tránh DEL
        }

        // Nếu pool đang rỗng, không thể DEL được
        if (active_pool.empty() && op_type > 30 && op_type <= 60) {
            op_type = rand_int(1, 2) == 1 ? 10 : 80; // Đổi sang ADD hoặc ASK
        }

        if (op_type <= 30) {
            // Lệnh ADD
            int x = rand_int(1, 1000);
            int k;
            if (group == 2) k = rand_int(1, bl); // Light
            else if (group == 3) k = rand_int(bl + 1, max_k); // Heavy
            else k = rand_int(1, max_k); // Mixed
            
            fout << "ADD " << x << " " << k << "\n";
            active_pool.push_back({x, k});
            
        } else if (op_type <= 60) {
            // Lệnh DEL
            int idx = rand_int(0, active_pool.size() - 1);
            pair<int, int> to_del = active_pool[idx];
            
            // Xóa nhanh phần tử khỏi vector O(1)
            swap(active_pool[idx], active_pool.back());
            active_pool.pop_back();
            
            fout << "DEL " << to_del.first << " " << to_del.second << "\n";
            
        } else {
            // Lệnh ASK
            int t = rand_int(1, max_t);
            fout << "ASK " << t << "\n";
        }
    }
    
    fout.close();
}

// ==========================================
// CHƯƠNG TRÌNH CHÍNH
// ==========================================
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string base_dir = "TEST_QUANLYTAICHIENDICHDINHKY";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++) {
        string dir_name = base_dir + "/";
        if (t < 10) dir_name += "0";
        dir_name += to_string(t);

        system(("mkdir -p " + dir_name).c_str());

        string inp_file = dir_name + "/F.inp";
        string out_file = dir_name + "/F.out";

        cout << "Đang sinh test " << t << " (Nhóm " << (t - 1) / 10 + 1 << ")...\n";
        
        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! Đã sinh 50 tests cho bài F tại thư mục " << base_dir << " =)))\n";
    return 0;
}