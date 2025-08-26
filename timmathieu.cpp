  #include <bits/stdc++.h>
using namespace std;

string s;
long long m, n, k, x, p[1000005];

int main(){
    freopen("mathieu.inp", "r", stdin);
    freopen("mathieu.out", "w", stdout);

    cin >> s;

    x = s.size();

    cin >> m;

     for (int i = 1; i <= m; i++){
        cin >> n;
        p[n]++;
    }

    for (int i = 0; i <= x / 2; i++){
        p[i] += p[i - 1];
        //cout << p[i] << endl;
    }

    for (int i = 0; i <= x / 2; i++){
        if (p[i] % 2 != 0) swap(s[i - 1], s[x - i]);
    }

    cout << s;

    return 0;
}
