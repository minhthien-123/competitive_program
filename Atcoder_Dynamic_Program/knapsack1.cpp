#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;
const long long maxn = 1e2+5;
const long long maxw = 1e5+5;

long long i, j, n, W, w[maxn], v[maxw], ans;
long long f[maxn][maxw];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
x
    cin >> n >> W;
    for (i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    f[0][0] = 0;
    for (i = 1; i <= W; i++)
        f[0][i] = -INF;

    for (i = 1; i <= n; i++){
        for (j = 0; j <= W; j++){
            f[i][j] = f[i - 1][j];
            if (j - w[i] >= 0) f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
        }
    }

    ans = -INF;
    for (i = 0; i <= W; i++)
        ans = max(ans, f[n][i]);

    cout << ans;

}