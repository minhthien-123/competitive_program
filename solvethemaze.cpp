#include <bits/stdc++.h>
#define task "solvethea"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n, m, t;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, 1,-1};
bool vis[100][100];

bool valid(int x,int y) {
	if(x <= 0 || x > n || y <= 0 || y > m)
        return false;
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> t;
	while(t--){
		std::cin >> n >> m;
		char a[51][51];
		for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                std::cin >> a[i][j];
                vis[i][j] = 0;
            }
        }

		for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i][j] == 'B') {
                    for(int k = 0; k < 4; k ++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(valid(nx, ny) && a[nx][ny] == '.')
                            a[i + dx[k]][j + dy[k]] = '#';
                    }
                }
            }
        }

		std::queue<ii> q;
		if(a[n][m] == '.')
            q.push({n, m});

		while(q.size()){
			int x=q.front().fi;
            int y=q.front().se;
            q.pop();
			
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(valid(nx,ny) && !vis[nx][ny] && a[nx][ny] != '#') {
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
		}

        bool flag = 1;
		for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if((a[i][j] == 'G' && !vis[i][j]) || (a[i][j] == 'B' && vis[i][j])) {
                    flag = 0;
                    break;
                }
            }
        }
		if (flag) std::cout << "YES\n";
		else	  std::cout << "NO\n";
	}

	return 0;
}