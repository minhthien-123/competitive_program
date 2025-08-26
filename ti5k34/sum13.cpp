#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ld long double
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

ld n, ans=0;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

    std::cin >> n;

    for(int i = 1; i <= n; i++){
        if(i % 2 != 0) 
        	ans += 1 / ((ld) i * i);
        else 
        	ans -= 1 / ((ld) i * i);
    }

    std::cout << std::fixed << std::setprecision(5) << ans;

    return 0;
}