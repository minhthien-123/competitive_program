#include <bits/stdc++.h>
using namespace std;

#define int long long

void decToHexa(int n) {
    char a[100];
    int i = 0;
    while (n != 0) {
        int temp = n % 16;
        if (temp < 10) {
            a[i] = temp + 48;
            i++;
        } else {
            a[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << a[j];
}

signed main() {
    int n;
    std::cin >> n;
    decToHexa(n);
    return 0;
}
