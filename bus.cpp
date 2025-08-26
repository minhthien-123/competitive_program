#include <bits/stdc++.h>
using namespace std;

struct num{
    int val;
    int dex;
};

int n, x, y, m, p;
num a[10005];

bool ss(num a, num b){
    return a.val < b.val;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> p;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        a[i].val = y;
        a[i].dex = x;
    }

    sort(a, a + n, ss);

    for (int i = 0; i < n; i++) cout << a[i].val << " " << a[i].dex << "\n";

}
