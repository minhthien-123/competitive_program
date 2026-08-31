#include <bits/stdc++.h>
using namespace std;

const long long maxn = 3e3 + 10;

long long n, m, i, j, f[maxn][maxn];
string s, t, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s >> t;
    n = s.size();
    m = t.size();

    s = " " + s;
    t = " " + t;

    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            if (s[i] == t[j]){
                f[i][j] = f[i - 1][j - 1] + 1;
            }else{
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    //cout << f[n][m] << "\n";

    i = n;
    j = m;
    while (i > 0 && j > 0){
        if (s[i] == t[j]){
			ans = s[i] + ans;
			i --;
			j --;
		}else if (f[i][j] == f[i-1][j]) i--;
		else j--;
    }

    cout << ans;

    return 0;
}

