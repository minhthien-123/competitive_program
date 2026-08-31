// gen.cpp
#include <bits/stdc++.h>
#ifdef _WIN32
#include <direct.h> // _mkdir
#define MKDIR(d) _mkdir(d)
#define CX_BIN "cx.exe"
#else
#include <sys/stat.h> // mkdir
#define MKDIR(d) mkdir(d, 0755)
#define CX_BIN "./cx"
#endif

using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// random integer in [l..r]
long long rnd(long long l, long long r)
{
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main()
{
    const int TOTAL = 10;
    const int SUB1 = 6;             // 60%
    const long long B1 = 1000000;    // bound sub1
    const long long B2 = 1000000000; // bound sub2

    MKDIR("cx");

    for (int tc = 1; tc <= TOTAL; tc++)
    {
        // tạo thư mục cx/XX
        char dir[16];
        sprintf(dir, "cx/%02d", tc);
        MKDIR(dir);

        // mở cx.inp
        char fin[32];
        sprintf(fin, "%s/cx.inp", dir);
        ofstream f(fin);
        if (!f)
        {
            cerr << "❌ Không tạo được " << fin << "\n";
            return 1;
        }

        bool isSub1 = (tc <= SUB1);
        // 1) Q
        int Q = isSub1
                    ? (int)rnd(1, 1000)    // Q nhỏ
                    : (int)rnd(1, 100000); // Q lớn
        f << Q << "\n";

        // 2) Q dòng a,b,c,n
        long long M = isSub1 ? B1 : B2;
        for (int i = 0; i < Q; i++)
        {
            long long a = rnd(1, M);
            long long b = rnd(1, M);
            long long c = rnd(1, M);
            long long n = rnd(0, M);
            f << a << " " << b << " " << c << " " << n << "\n";
        }
        f.close();

        // 3) gọi cx để sinh cx.out
        char cmd[256];
        sprintf(cmd, "%s < %s > %s/cx.out", CX_BIN, fin, dir);
        if (system(cmd) != 0)
        {
            cerr << "❌ Lỗi khi chạy: " << cmd << "\n";
            return 1;
        }

        cout << "✔ Generated " << setw(2) << setfill('0') << tc << "\n";
    }

    cout << "🎉 Đã sinh xong 50 test trong cx/01…cx/50\n";
    return 0;
}
