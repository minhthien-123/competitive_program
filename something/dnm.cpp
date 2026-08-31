#include <bits/stdc++.h>
using namespace std;

long long n, i, s, x, m, l, m1, d, k, l1;
bool kt = true;

void make(long long k){
    s = 0;
    l = 0;
    l1 = 0;
    while (k % 10 != k){
        if (k % 10 == 0) l++;
        l1++;
        s += 1;
        s *= 10;
        k /= 10;
    }

    l1++;
    l++;
    s++;
}

void make2(long long k){
    m = LLONG_MAX;
    m1 = LLONG_MAX;
    while (k % 10 != k){
        if (k % 10 != 0) m1 = min(m1, k % 10);
        m = min(m, k % 10);
        k /= 10;
    }

    m = min(m, k);
    if (k != 0) m1 = min(m1, k);
}

void make3(long long k){
    while ((k / 10) % 10 != (k / 10)){
        k /= 10;
    }
    d = k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("dnm.inp", "r", stdin);
    freopen("dnm.out", "w", stdout);

    cin >> n;
    make(n);
    make2(n);
    make3(n);
    if (n % 10 == 0){
        cout << s / 10 * 9;
    }else if (m == 0){
        cout << 9 * s / 10;
    }else cout << m * s;
}
