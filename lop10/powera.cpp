#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const ll mod = 21111983;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	ll n, a;
	std::cin >> n >> a;
	n--;
	ll tmp = a;
	while (n--)
		a = (a % mod) * (tmp % mod) % mod;
	
	std::cout << a;

	return 0;
}