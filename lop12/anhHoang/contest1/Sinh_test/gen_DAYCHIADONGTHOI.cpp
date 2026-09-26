#include <bits/stdc++.h>

using namespace std;

// ==========================================
// CẤU HÌNH VÀ HÀM RANDOM
// ==========================================
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_int(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

const int maxn = 2e5;
const int maxv = 1e6; // a_i và x_i lên đến 10^6

// ==========================================
// CẤU TRÚC DỮ LIỆU CỦA NGƯỜI DÙNG (Để tạo Output)
// ==========================================
int a_sol[maxn + 7];
vector<int> divs[maxv + 7];
int n, q;

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
void generate_output(string inp_file, string out_file) {
    ifstream fin(inp_file);
    ofstream fout(out_file);

    fin >> n >> q;
    
    // Reset divs array cho mỗi test
    for (int i = 1; i <= maxv; i++) {
        divs[i].clear();
    }

    for (int i = 1; i <= n; i++) {
        fin >> a_sol[i];
        if (a_sol[i] == 0) continue; // Bỏ qua 0 vì 0 chia x_i vẫn là 0

        for (int j = 1; j * j <= a_sol[i]; j++) {
            if (a_sol[i] % j == 0) {
                divs[j].push_back(i);
                if (j * j != a_sol[i]) {
                    divs[a_sol[i] / j].push_back(i);
                }
            }
        }
    }

    while (q--) {
        int x;
        fin >> x;

        if (x == 1 || x > maxv) {
            continue;
        }

        vector<int> tmp;
        for (int i : divs[x]) {
            if (a_sol[i] % x == 0) {
                a_sol[i] /= x;
                tmp.push_back(i);
            }
        }
        divs[x] = move(tmp);
    }

    for (int i = 1; i <= n; i++) {
        fout << a_sol[i] << (i == n ? "" : " ");
    }
    fout << "\n";
}

// ==========================================
// CHUẨN BỊ SỐ NGUYÊN TỐ CHO SUBTASK 4
// ==========================================
vector<int> primes;
void sieve_primes() {
    vector<bool> is_prime(maxv + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= maxv; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= maxv; j += i)
                is_prime[j] = false;
        }
    }
}

// ==========================================
// HÀM SINH INPUT THEO TỪNG SUBTASK
// ==========================================
int get_subtask(int t) {
    return (t - 1) / 10 + 1; // 50 test, mỗi subtask 10 test
}

void generate_input(int t, string inp_file) {
    ofstream fout(inp_file);
    int sub = get_subtask(t);

    int n_max = 200000, q_max = 100000, a_max = 1000000;
    
    // Thiết lập ràng buộc theo subtask
    if (sub == 1) { n_max = 2000; q_max = 2000; }
    else if (sub == 2) { a_max = 1000; }

    // Test đầu tiên của mỗi subtask cho max giới hạn
    int cur_n = (t % 10 == 1) ? n_max : rand_int(max(1.0, n_max * 0.8), n_max);
    int cur_q = (t % 10 == 1) ? q_max : rand_int(max(1.0, q_max * 0.8), q_max);

    fout << cur_n << " " << cur_q << "\n";

    for (int i = 1; i <= cur_n; i++) {
        fout << rand_int(0, a_max) << (i == cur_n ? "" : " ");
    }
    fout << "\n";

    for (int i = 1; i <= cur_q; i++) {
        long long x = 1;
        if (sub == 3) {
            // Lũy thừa của 2, lớn nhất là 2^19 vì x_i <= 10^6
            x = 1LL << rand_int(0, 19);
        } 
        else if (sub == 4) {
            // Số nguyên tố
            x = primes[rand_int(0, primes.size() - 1)];
        } 
        else {
            // Để test có tỉ lệ thay đổi nhiều, tạo xác suất 40% query chia số nhỏ
            if (rand_int(1, 100) <= 40) {
                x = rand_int(2, 20); 
            } else {
                x = rand_int(1, maxv);
            }
        }
        fout << x << "\n";
    }
    fout.close();
}

// ==========================================
// CHƯƠNG TRÌNH CHÍNH
// ==========================================
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // Khởi tạo trước mảng số nguyên tố
    sieve_primes();

    string base_dir = "TEST_DAYCHIADONGTHOI";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++) {
        // Đặt tên folder 01, 02 ... 50
        string dir_name = base_dir + "/";
        if (t < 10) dir_name += "0";
        dir_name += to_string(t);

        system(("mkdir -p " + dir_name).c_str());

        string inp_file = dir_name + "/B.inp";
        string out_file = dir_name + "/B.out";

        cout << "Đang sinh test " << t << " (Subtask " << get_subtask(t) << ")...\n";
        
        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! Đã sinh thành công " << total_tests << " tests tại thư mục " << base_dir << " :)))\n";
    return 0;
}