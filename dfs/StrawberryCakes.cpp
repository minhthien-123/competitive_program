#include <bits/stdc++.h>
#define task "StrawberryCakes"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 307;

int h, w, k;
int f[maxn][maxn], b[maxn][maxn];
std::vector<ii> a;
char c[maxn][maxn];

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> h >> w >> k;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			std::cin >> c[i][j];
			if (c[i][j] == '#')
				a.pb({i, j});
		}
	}

	//for (ii i : a)
		//std::cout << i.fi << " " << i.se << "\n";

	int cnt = 0;
	for (ii i : a){
		cnt++;
		b[i.fi][i.se] = cnt;
		for (int j = i.se + 1; j <= w; j++)
			if (c[i.fi][j] == '.') b[i.fi][j] = cnt;
			else				   break;
		for (int j = i.se - 1; j >= 1; j--)
			if (c[i.fi][j] == '.') b[i.fi][j] = cnt;
			else			  	   break;
	}

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (b[i][j] == 0 && b[i - 1][j] != 0)
				b[i][j] = b[i - 1][j];

	for (int i = h; i >= 1; i--)
		for (int j = w; j >= 1; j--)
			if (b[i][j] == 0 && b[i + 1][j] != 0)
				b[i][j] = b[i + 1][j];

	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++)
			std::cout << b[i][j] << " ";
		std::cout << "\n";
	}

	return 0;
}