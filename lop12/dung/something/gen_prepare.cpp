#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_int(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

long long solve_prepare(long long n, long long m, const vector<long long>& a) {
    long long mid = n / 2;
    vector<long long> v1, v2;

    for (long long mask = 0; mask < (1LL << mid); mask++) {
        long long sum = 0;
        for (long long i = 0; i < mid; i++) {
            if (mask & (1LL << i)) sum = (sum + a[i]) % m;
        }
        v1.push_back(sum);
    }

    long long rem = n - mid;
    for (long long mask = 0; mask < (1LL << rem); mask++) {
        long long sum = 0;
        for (long long i = 0; i < rem; i++) {
            if (mask & (1LL << i)) sum = (sum + a[mid + i]) % m;
        }
        v2.push_back(sum);
    }

    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    long long ans = 0;
    for (long long x : v1) {
        auto it = upper_bound(v2.begin(), v2.end(), m - 1 - x);
        if (it != v2.begin()) {
            ans = max(ans, x + *prev(it));
        }
        ans = max(ans, (x + v2.back()) % m);
    }
    return ans;
}

int main() {
    int num_tests = 20;
    string task_name = "prepare";

    for (int i = 1; i <= num_tests; i++) {
        // Tạo tên thư mục con dạng 01, 02,...
        string folder_num = (i < 10 ? "0" : "") + to_string(i);
        string dir_path = task_name + "/" + folder_num;

        // Tạo thư mục nếu chưa có
        fs::create_directories(dir_path);

        string inp_name = dir_path + "/" + task_name + ".inp";
        string out_name = dir_path + "/" + task_name + ".out";

        long long n, m;
        if (i <= 5) {
            n = rand_int(1, 10);
            m = rand_int(1, 1000);
        } else if (i <= 10) {
            n = rand_int(10, 20);
            m = rand_int(1000, 1000000);
        } else if (i <= 15) {
            n = rand_int(20, 30);
            m = rand_int(1e9, 1e12);
        } else {
            n = 35;
            m = rand_int(1e12, 1e14);
        }

        vector<long long> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = rand_int(0, 1e14);
        }

        // Ghi file input
        ofstream fin(inp_name);
        fin << n << " " << m << "\n";
        for (int j = 0; j < n; j++) {
            fin << a[j] << (j == n - 1 ? "" : " ");
        }
        fin.close();

        // Chạy logic sinh output
        long long ans = solve_prepare(n, m, a);

        // Ghi file output
        ofstream fout(out_name);
        fout << ans << "\n";
        fout.close();

        cout << "Da sinh xong test " << folder_num << " cho bai Prepare!\n";
    }
    return 0;
}