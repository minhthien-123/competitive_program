#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int t;
int countt[N + 5], ans[11][N + 5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 2; i <= N; i++){
        if (countt[i] == 0){
            for (int j = i; j <= N; j += i) countt[j]++;
        }
    }

    for (int i = 0; i <= 10; i++){
        for (int j = 1; j <= N; j++){
            int tmp = 0;
            if (countt[j] == i) tmp = 1;
            ans[i][j] = ans[i][j - 1] + tmp;
        }
    }

    cin >> t;
    while (t--){
        int a, b, n;
        cin >> a >> b >> n;
        cout << ans[n][b] - ans[n][a - 1] << "\n";
    }
}
