#include <bits/stdc++.h>
const int MOD = 100000000;
using namespace std;
typedef vector<int> big;

int n, k;
big F[10005];

big operator + (const big &a, const big &b) {
    big c; int carry = 0;
    for(int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        c.push_back(carry % MOD);
        carry /= MOD;
    }
    if (carry) c.push_back(carry);
    return c;
}

big operator - (const big &a, const big &b) {
    big c; int borrow = 0, s;
    for(int i = 0; i < a.size(); i++) {
        s = a[i] - borrow;
        if (i < b.size()) s -= b[i];
        if (s < 0) {
            s += MOD;
            borrow = 1;
        }
        else
            borrow = 0;
        c.push_back(s);
    }
    while (!c.empty() && c[c.size() - 1] == 0) c.pop_back();
    return c;

}

void print(big a) {
    printf("%d", a[a.size() - 1]);
    for(int i = a.size() - 2; i >= 0; i--)
        printf("%08d", a[i]);
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &k);
    F[0].push_back(1);
    big prev; prev.push_back(1);
    big POW; POW.push_back(1);
    for(int i = 1; i <= n + 1; i++) {
        F[i] = prev;
        prev = prev + F[i];
        if (i >= k)
            prev = prev - F[i - k];
        if (i <= n)
            POW = POW + POW;
    }
    print(POW - F[n + 1]);
    return 0;
}
