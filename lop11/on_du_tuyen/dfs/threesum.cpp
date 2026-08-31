#include <bits/stdc++.h>
#define task "threesum"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int os = 1e6;
const int maxn = 5e3 + 7;

int n, q, a[maxn], d[2000007];
ll f[maxn][maxn];

signed main (){
	std::ios_base::sync_with_stdio(0);
  	std::cin.tie(0); std::cout.tie(0);

  	std::freopen(task".inp",  "r", stdin);
  	std::freopen(task".out", "w", stdout);

  	std::cin >> n >> q;
  	for(int i =1 ;i<=n;i++){
    	std::cin >> a[i];
    	a[i] += os;
  	}

  	for(int i = 1; i <= n; i++){
   		for(int j = i + 1; j <= n; j++){
     		ll s = 3 * os - a[i] - a[j];
     		if(j - 1 > i && s >= 0 && s <= 2 * os) f[i][j] = d[s];
     		d[a[j]]++;
   		}
   		for(int j = i + 1; j <= n; j++) 
   			d[a[j]]--;
  	}

  	for(int i = 1; i <= n; i++) 
   		for(int j = 1; j <= n; j++) 
     		f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i -1 ][j - 1];

    while(q--){
       	int l, r;
       	std::cin >> l >> r;
       	std::cout << f[r][r] - f[l - 1][r] - f[r][l - 1] +f[l - 1][l - 1] << '\n';
    }
}