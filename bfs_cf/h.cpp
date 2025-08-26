#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii std::pair<int, int>

const int maxn = 15;
ii a, b;
int dx[] = {2, -2, -2, 2};
int dy[] = {-2, 2, -2, 2};
int vis[maxn][maxn], d[maxn][maxn];
bool flag;
std::queue<ii> q;

bool check(int x, int y){
    if (vis[x][y] || x < 1 || y < 1 || x > 8 || y > 8) return false;
    return true;
}

void bfs(int x, int y){
    while (!q.empty()){
        ii l = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = l.fi + dx[i], ny = l.se + dy[i];
            if (check(nx, ny)){
                q.push({nx, ny});
                d[nx][ny] = d[l.fi][l.se] + 1;
                vis[nx][ny] = true;
                if (b.fi == nx && b.se == ny){
                    flag = true;
                    return;
                }
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> a.fi >> a.se >> b.fi >> b.se;

    q.push(a);
    vis[a.fi][a.se] = true;

    bfs(b.fi, b.se);

    if(flag || a == b)
        std::cout << d[b.fi][b.se];
    else
        std::cout << -1;

    return 0;
}
