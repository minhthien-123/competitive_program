#include "testlib.h"
#include <bits/stdc++.h>

const double EPS = 1e-3;

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    double ja = ans.readDouble();
    double pa = ouf.readDouble();

    if (fabs(ja - pa) > EPS + 1E-15)
        quitf(_wa, "Kết quả đúng là %.10f, Kết quả của bạn là %.10f", ja, pa);

    quitf(_ok, "Kết quả đúng");
}