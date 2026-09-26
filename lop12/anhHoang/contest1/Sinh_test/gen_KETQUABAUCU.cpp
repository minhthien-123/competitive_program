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

const int maxn = 100005;

// ==========================================
// BIẾN TOÀN CỤC CHO TRÌNH GIẢI (OUTPUT)
// ==========================================
int a_col[maxn + 7];
vector<int> adj[maxn + 7];
int vis[maxn + 7];
int timer_dfs = 0;
vector<int> color_group[maxn + 7];
vector<int> active_colors;
pair<int, int> edges_arr[maxn + 7];
int cnt[maxn + 7], rep[maxn + 7];

struct DSU {
    vector<int> par, sz;
    DSU(int n) {
        par.resize(n + 7);
        sz.resize(n + 7, 1);
        for (int i = 0; i <= n + 1; i++) par[i] = i;
    }
    int acs(int v) {
        return v == par[v] ? v : par[v] = acs(par[v]);
    }
    void join(int u, int v) {
        u = acs(u); v = acs(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
            if (adj[u].empty()) adj[u].swap(adj[v]);
            else {
                adj[u].insert(adj[u].end(), adj[v].begin(), adj[v].end());
                adj[v].clear();
            }
        }
    }
};

// ==========================================
// HÀM CHẠY GIẢI PHÁP ĐỂ TẠO .OUT
// ==========================================
void solve_testcase(ifstream &fin, ofstream &fout) {
    int n, m, k;
    if (!(fin >> n >> m >> k)) return;

    for (int i = 0; i <= k; i++) {
        cnt[i] = 0;
        rep[i] = 0;
        color_group[i].clear();
    }
    active_colors.clear();

    for (int i = 1; i <= n; i++) {
        fin >> a_col[i];
        vector<int>().swap(adj[i]);
    }

    DSU dsu(n);

    for (int i = 1; i <= m; i++) {
        int u, v;
        fin >> u >> v;
        edges_arr[i] = {u, v};
        if (a_col[u] == a_col[v]) {
            dsu.join(u, v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dsu.acs(i) == i) {
            cnt[a_col[i]]++;
            rep[a_col[i]] = i;
        }
    }

    for (int i = 1; i <= m; i++) {
        auto [u, v] = edges_arr[i];
        if (a_col[u] != a_col[v]) {
            adj[dsu.acs(u)].push_back(dsu.acs(v));
            adj[dsu.acs(v)].push_back(dsu.acs(u));
        }
    }

    queue<int> q;
    for (int i = 1; i <= k; i++) {
        if (cnt[i] == 1) {
            int u = dsu.acs(rep[i]);
            a_col[u] = 0;
            q.push(u);
            cnt[i] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        u = dsu.acs(u);
        timer_dfs++;
        active_colors.clear();

        for (int v : adj[u]) {
            v = dsu.acs(v);
            if (u != v && vis[v] != timer_dfs) {
                vis[v] = timer_dfs;
                int c = a_col[v];
                if (color_group[c].empty()) {
                    active_colors.push_back(c);
                }
                color_group[c].push_back(v);
            }
        }
        adj[u].clear();

        bool check = false;
        if (!color_group[0].empty()) {
            auto &vec = color_group[0];
            int base = vec[0];
            for (int i = 1; i < (int)vec.size(); i++) {
                int nxt = vec[i];
                if (dsu.acs(base) != dsu.acs(nxt)) {
                    dsu.join(base, nxt);
                    base = dsu.acs(base);
                }
            }
            if (dsu.acs(u) != dsu.acs(base)) {
                dsu.join(u, base);
                u = dsu.acs(u);
                check = true;
            }
            vec.clear();
        }

        for (int c : active_colors) {
            if (c == 0) continue;
            auto &vec = color_group[c];
            int base = vec[0];
            for (int i = 1; i < (int)vec.size(); i++) {
                int nxt = vec[i];
                if (dsu.acs(base) != dsu.acs(nxt)) {
                    dsu.join(base, nxt);
                    base = dsu.acs(base);
                    cnt[c]--;
                }
            }
            if (cnt[c] == 1) {
                a_col[base] = 0;
                cnt[c] = 0;
                q.push(base);
            }
            adj[u].push_back(base);
            vec.clear();
        }

        if (check) q.push(u);
    }

    bool ok = true;
    for (int i = 1; i <= k; i++) {
        if (cnt[i] > 0) {
            ok = false;
            break;
        }
    }

    fout << (ok ? "YES\n" : "NO\n");
}

void generate_output(string inp_file, string out_file) {
    ifstream fin(inp_file);
    ofstream fout(out_file);
    
    // Reset global state
    timer_dfs = 0;
    for(int i=0; i<=maxn; i++) vis[i] = 0;
    
    int tt;
    if (fin >> tt) {
        while (tt--) {
            solve_testcase(fin, fout);
        }
    }
}

// ==========================================
// HÀM SINH INPUT THEO NHÓM
// ==========================================
void generate_input(int test_num, string inp_file) {
    ofstream fout(inp_file);
    int group = (test_num - 1) / 10;
    
    int t_cases = rand_int(5, 20);
    if (group == 4) t_cases = rand_int(1, 5); // Nhóm kịch trần hạn chế số lượng t
    if (test_num % 10 == 0) t_cases = 100;    // Max t = 100 theo đề bài

    fout << t_cases << "\n";
    
    long long rem_n = 100000, rem_m = 100000, rem_k = 100000;

    for (int t = 1; t <= t_cases; t++) {
        long long n, m, k;
        
        if (t == t_cases && test_num % 10 == 0) {
            n = rem_n; m = rem_m; k = rem_k;
        } else {
            long long avg_n = rem_n / (t_cases - t + 1);
            long long avg_m = rem_m / (t_cases - t + 1);
            long long avg_k = rem_k / (t_cases - t + 1);
            n = rand_int(max(1LL, avg_n / 2), avg_n);
            m = rand_int(max(1LL, avg_m / 2), avg_m);
            k = rand_int(max(1LL, avg_k / 2), avg_k);
        }
        
        n = max(1LL, min(n, 100000LL));
        
        // Điều chỉnh đồ thị theo nhóm
        if (group == 1) m = n - 1; // Tree
        if (group == 2) m = n - 1; // Path
        if (group == 3) {
            n = min(n, 500LL);
            m = min(m, n * (n - 1) / 2); // Dense
        }
        
        m = max(1LL, min(m, n * (n - 1) / 2));
        k = max(1LL, min(k, 100000LL));

        rem_n -= n; rem_m -= m; rem_k -= k;

        fout << n << " " << m << " " << k << "\n";

        for (int i = 1; i <= n; i++) {
            fout << rand_int(1, k) << (i == n ? "" : " ");
        }
        fout << "\n";

        set<pair<int, int>> edges;
        if (group == 2) {
            // Path graph
            for (int i = 1; i < n; i++) {
                fout << i << " " << i + 1 << "\n";
            }
        } else if (group == 1) {
            // Tree graph
            for (int i = 2; i <= n; i++) {
                int u = rand_int(1, i - 1);
                fout << i << " " << u << "\n";
            }
        } else {
            // Random graph
            int edges_generated = 0;
            while (edges_generated < m) {
                int u = rand_int(1, n);
                int v = rand_int(1, n);
                if (u != v) {
                    int mn = min(u, v), mx = max(u, v);
                    if (edges.find({mn, mx}) == edges.end()) {
                        edges.insert({mn, mx});
                        fout << mn << " " << mx << "\n";
                        edges_generated++;
                    }
                }
            }
        }
    }
    fout.close();
}

// ==========================================
// CHƯƠNG TRÌNH CHÍNH
// ==========================================
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string base_dir = "TEST_KETQUABAUCU";
    system(("mkdir -p " + base_dir).c_str());

    int total_tests = 50;

    for (int t = 1; t <= total_tests; t++) {
        string dir_name = base_dir + "/";
        if (t < 10) dir_name += "0";
        dir_name += to_string(t);

        system(("mkdir -p " + dir_name).c_str());

        string inp_file = dir_name + "/E.inp";
        string out_file = dir_name + "/E.out";

        cout << "Đang sinh test " << t << " (Nhóm " << (t - 1) / 10 + 1 << ")...\n";
        
        generate_input(t, inp_file);
        generate_output(inp_file, out_file);
    }

    cout << "\nXONG! Đã sinh 50 tests cho bài E tại thư mục " << base_dir << " =)))\n";
    return 0;
}