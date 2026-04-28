#include <bits/stdc++.h>
#define task "m"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 107;
const int inf  = 1e9;

int n, l = inf, h = -inf, res = inf;
int a[maxn][maxn];
int dx[] = {-1, 0, 0, 1};
int dy[] = { 0, 1,-1, 0};

bool check(int x, int y){
	if (x < 1 || y < 1 || x > n || y > n) return false;
	return true;
}

bool bfs(int x, int y, int u, int v, bool vis[maxn][maxn]){
	std::queue<ii> q;
    q.push({x,y});
    vis[x][y] = true;

    while(q.size()){
		ii s = q.front();
        q.pop();

        for(int k = 0;k < 4; k++){
            int nx = s.fi + dx[k], ny = s.se + dy[k];
            if(!vis[nx][ny] && check(nx, ny) && (u <= a[nx][ny] && a[nx][ny] <= v)){
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return vis[n][n];
}
signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			std::cin >> a[i][j];
			l = std::min(l, a[i][j]);
			h = std::max(h, a[i][j]);
		}

	for (int i = l; i <= h; i++)
		for (int j = i; j <= h; j++)
			if (i <= a[1][1] && a[1][1] <= j){
				bool vis[maxn][maxn] = {false};

				if (bfs(1, 1, i, j, vis))
					res = std::min(res, j - i);
			}

	std::cout << res;

	return 0;
}