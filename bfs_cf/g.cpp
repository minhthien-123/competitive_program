#include <bits/stdc++.h>
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second

const int maxn = 111;
int c[maxn][maxn], l[maxn][maxn];
char t[maxn];
int m, n, res = -1;
ii s, e;
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};

void bfs(ii s) {
    std::queue<ii> q;
    c[s.fi][s.se]=1;
    ii t;
    int x,y;
    q.push(s);
    while (!q.empty()){
        t = q.front();
        q.pop();
        x = t.fi;
        y = t.se;
        if (t == e){
            res = l[x][y];
            return;
        }for (int i = 0; i < 4; i++)
            if (c[x + dx[i]][y + dy[i]] == 0) {
                c[x + dx[i]][y + dy[i]] = 1;
                l[x + dx[i]][y + dy[i]] = 1 + l[x][y];
                q.push(ii(x + dx[i], y + dy[i]));
            }
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> m >> n;

    for (int i = 0; i <= m + 1; i++) {
        c[i][0]     = 2;
        c[i][n + 1] = 2;
    }

    for (int i = 0; i <= n + 1; i++) {
        c[0][i]     = 2;
        c[m + 1][i] = 2;
    }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            c[i][j] = 0;
            l[i][j] = 0;
        }

    for (int i = 1; i <= m; i++) {
        std::cin >> t;
        for (int j = 1; j <= n; j++){
            if (t[j - 1] == '*')
                c[i][j] = 2;
            if (t[j - 1] == 'B')
                s = ii(i, j);
            if (t[j - 1] == 'C')
                e = ii(i, j);
        }
    }

    bfs(s);

    std::cout << res;

    return 0;
}
