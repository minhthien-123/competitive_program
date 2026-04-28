#include <bits/stdc++.h>
using namespace std;

long long n, s, i;
bool kt;

bool is_prime(long long t){
    bool flag = true;
    if (t < 2) flag = false;
    for (i = 2; i <= trunc(sqrt(t)); i++)
        if (t % i == 0) flag = false;
    return flag;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("sprime.inp", "r", stdin);
    freopen("sprime.out", "w", stdout);

    cin >> n;
    s = n * (n + 1) / 2 - 1;

    cout << s << "\n";

    kt = is_prime(s);
    if (kt) cout << "YES";
    else    cout << "NO";
}