// gen.cpp
#include <bits/stdc++.h>
#ifdef _WIN32
#include <direct.h>
#define MKDIR(d) _mkdir(d)
#define SOL_BIN "kd.exe"
#else
#include <sys/stat.h>
#define MKDIR(d) mkdir(d, 0755)
#define SOL_BIN "./kd"
#endif

using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// random int in [l..r]
int ri(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(rng);
}

// sinh giá trị với phân phối biased: P(zero)=p0, P(neg)=p_neg, P(pos)=p_pos
int biased_val(double p0, double p_neg, double p_pos)
{
    uniform_real_distribution<double> d(0, 1);
    double x = d(rng);
    if (x < p0)
        return 0;
    else if (x < p0 + p_neg)
        return ri(-1000000, -1);
    else
        return ri(1, 1000000);
}

int main()
{
    // cấu hình tỉ lệ zero/neg/pos
    const double P0_S = 0.3, PNEG_S = 0.35, PPOS_S = 0.35; // sub1
    const double P0_L = 0.3, PNEG_L = 0.35, PPOS_L = 0.35; // sub2

    MKDIR("kd");
    const int TOTAL = 50;
    const int SUB1 = int(TOTAL * 0.6 + 1e-9); // =30

    for (int tc = 1; tc <= TOTAL; tc++)
    {
        // tạo kd/XX
        char dir[32];
        sprintf(dir, "kd/%02d", tc);
        MKDIR(dir);

        // mở kd.inp
        string fin = string(dir) + "/kd.inp";
        ofstream f(fin);
        int N;
        if (tc <= SUB1)
        {
            // Sub1: N nhỏ
            N = ri(5, 20);
            vector<int> a(N);
            for (int i = 0; i < N; i++)
                a[i] = biased_val(P0_S, PNEG_S, PPOS_S);
            // đảm bảo ít nhất 1 cặp không dương
            bool ok = false;
            for (int i = 0; i < N && !ok; i++)
                for (int j = i + 1; j < N; j++)
                {
                    if ((a[i] == 0 && a[j] != 0) || (a[j] == 0 && a[i] != 0) || (a[i] < 0 && a[j] < 0))
                    {
                        ok = true;
                        break;
                    }
                }
            if (!ok)
            {
                a[0] = 0;
                if (N > 1)
                    a[1] = -1;
            }
            f << N << "\n";
            for (int x : a)
                f << x << " ";
            f << "\n";
        }
        else
        {
            // Sub2: N lớn
            N = ri(100000, 200000);
            vector<int> a(N);
            for (int i = 0; i < N; i++)
                a[i] = biased_val(P0_L, PNEG_L, PPOS_L);
            // đảm bảo ít nhất 1 cặp không dương
            a[0] = 0;
            if (N > 1)
                a[1] = -1;
            f << N << "\n";
            for (int x : a)
                f << x << " ";
            f << "\n";
        }
        f.close();

        // chạy kd để tạo kd.out
        string fout = string(dir) + "/kd.out";
        string cmd = string(SOL_BIN) + " < " + fin + " > " + fout;
        if (system(cmd.c_str()) != 0)
        {
            cerr << "❌ lỗi khi chạy: " << cmd << "\n";
            return 1;
        }
        cout << "✔ Generated " << setw(2) << setfill('0') << tc << "\n";
    }
    cout << "🎉 Đã sinh 50 test trong kd/01…xk/50\n";
    return 0;
}
