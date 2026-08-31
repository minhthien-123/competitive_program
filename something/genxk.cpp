// gen.cpp
#include <bits/stdc++.h>
#ifdef _WIN32
#include <direct.h> // _mkdir
#define MKDIR(dir) _mkdir(dir)
#define EXE_NAME "xk.exe"
#else
#include <sys/stat.h> // mkdir
#include <sys/types.h>
#define MKDIR(dir) mkdir(dir, 0755)
#define EXE_NAME "./xk"
#endif

using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// Xác suất mỗi truy vấn sub2 là NO ngoài truy vấn bắt buộc đầu tiên
const double P_NO = 0.5;

// 1) Sinh xâu ngẫu nhiên độ dài [1..maxlen]
string rand_str(int maxlen)
{
    uniform_int_distribution<int> dl(1, maxlen);
    int L = dl(rng);
    string s;
    s.reserve(L);
    uniform_int_distribution<int> ch('a', 'z');
    for (int i = 0; i < L; i++)
        s.push_back(char(ch(rng)));
    return s;
}

// 2) Sinh xâu toàn ký tự giống nhau, độ dài [1..maxlen]
string same_str(int maxlen)
{
    uniform_int_distribution<int> dl(1, maxlen);
    int L = dl(rng);
    uniform_int_distribution<int> ch('a', 'z');
    char c = char(ch(rng));
    return string(L, c);
}

// Tạo subtask1: Q∈[5..20], 1 truy vấn NO đầu tiên, còn lại YES
void make_sub1(ofstream &f)
{
    uniform_int_distribution<int> dq(5, 20);
    int Q = dq(rng);
    f << Q << "\n";
    // Truy vấn NO
    f << same_str(10) << "\n";
    // Các truy vấn YES
    for (int i = 1; i < Q; i++)
        f << rand_str(10) << "\n";
}

// Tạo subtask2: Q∈[900..1000], ít nhất 1 NO, các truy vấn còn lại P_NO → NO / else YES
void make_sub2(ofstream &f)
{
    uniform_int_distribution<int> dq(90, 100);
    int Q = dq(rng);
    f << Q << "\n";

    uniform_int_distribution<int> dlen(50000, 100000);
    uniform_int_distribution<int> ch('a', 'z');
    uniform_real_distribution<double> prob(0.0, 1.0);

    // Truy vấn NO bắt buộc
    {
        int L = dlen(rng);
        string s;
        s.reserve(L);
        for (int i = 0; i < L; i++)
            s.push_back(char(ch(rng)));
        // đổi 1 ký tự
        uniform_int_distribution<int> didx(0, L - 1);
        int idx = didx(rng);
        char c2;
        do
        {
            c2 = char(ch(rng));
        } while (c2 == s[idx]);
        s[idx] = c2;
        f << s << "\n";
    }
    // Các truy vấn còn lại
    for (int i = 1; i < Q; i++)
    {
        int L = dlen(rng);
        string s;
        s.reserve(L);
        for (int j = 0; j < L; j++)
            s.push_back(char(ch(rng)));
        if (prob(rng) < P_NO)
        {
            // NO
            uniform_int_distribution<int> didx(0, L - 1);
            int idx = didx(rng);
            char c2;
            do
            {
                c2 = char(ch(rng));
            } while (c2 == s[idx]);
            s[idx] = c2;
        }
        // else giữ nguyên → YES
        f << s << "\n";
    }
}

int main()
{
    // 1) Tạo thư mục gốc "xk"
    MKDIR("xk");

    const int TOTAL = 10;
    const int SUB1 = int(TOTAL * 0.6 + 1e-9); // → 30

    for (int i = 1; i <= TOTAL; i++)
    {
        // 2) Tạo thư mục con "xk/XX"
        char dir[32];
        sprintf(dir, "xk/%02d", i);
        MKDIR(dir);

        // 3) Ghi input vào xk/XX/xk.inp
        char inp[64];
        sprintf(inp, "%s/xk.inp", dir);
        ofstream f_in(inp);
        if (!f_in)
        {
            cerr << "✖️ Không thể tạo " << inp << "\n";
            return 1;
        }

        if (i <= SUB1)
            make_sub1(f_in);
        else
            make_sub2(f_in);
        f_in.close();

        // 4) Gọi xk để tạo xk.out
        char cmd[256];
        sprintf(cmd, "%s < %s > %s/xk.out", EXE_NAME, inp, dir);
        if (system(cmd) != 0)
        {
            cerr << "✖️ Lỗi khi chạy `" << cmd << "`\n";
            return 1;
        }

        cout << "✔️ Generated test " << setw(2) << setfill('0') << i << "\n";
    }

    cout << "🎉 DONE! Đã sinh 50 test trong xk/01…xk/50\n";
    return 0;
}
