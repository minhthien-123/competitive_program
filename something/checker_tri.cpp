#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    long double x, y, a, b, c;
    x = inf.readDouble();
    y = inf.readDouble();

    a = ouf.readDouble();
    b = ouf.readDouble();
    c = ouf.readDouble();

    if ((a + b) == y && (c - a == x || c - b == x))
    {
        quitf(_ok, "Kết quả đúng");
    }else
    {
        quitf(_wa, "Kết quả sai");
    }
}
