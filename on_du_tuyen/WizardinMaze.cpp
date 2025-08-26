#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 7;
const ll inf = LLONG_MAX;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int c1, c2, d1, d2;
int h, w;
std::vector<std::vector<ll>> d(maxn, std::vector<ll>(maxn, inf));
std::priority_queue<std::pair<ll, ii>, std::vector<std::pair<ll, ii>>, std::greater<std::pair<ll, ii>>> pq;
std::vector<std::string> g(maxn);

bool check(int x, int y){
    if (x < 0 || y < 0 || x >= h || y >= w) return false;
    return true;
}

void bfs(){
    while (!pq.empty()) {
        auto [dist, t] = pq.top();
        pq.pop();
        int x = t.fi;
        int y = t.se;

        if (dist > d[x][y]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny)){
                if (d[nx][ny] > d[x][y] && g[nx][ny] != '#') {
                    d[nx][ny] = d[x][y];
                    pq.push({d[nx][ny], {nx, ny}});
                }
            }   
        }

        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                if (i == 0 && j == 0) continue;
                int nx = x + i;
                int ny = y + j;
                if (check(nx, ny)){
                    if (d[nx][ny] > d[x][y] + 1 && g[nx][ny] != '#') {
                        d[nx][ny] = d[x][y] + 1;
                        pq.push({d[nx][ny], {nx, ny}});
                    }
                }
            }
        }
    }
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> h >> w >> c1 >> c2 >> d1 >> d2;
    for (int i = 0; i < h; i++)
        std::cin >> g[i];
    
    d[c1 - 1][c2 - 1] = 0;    
    pq.push({0, {c1 - 1, c2 - 1}});

    bfs();

    if (d[d1 - 1][d2 - 1] == inf)
        std::cout << -1;
    else 
        std::cout << d[d1 - 1][d2 - 1];

    return 0;
}