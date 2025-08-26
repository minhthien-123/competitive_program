#include <bits/stdc++.h>
#define task ""
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n, a, b;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);

	std::cin >> n;

	if (n >= 3600){
		a = n / 3600;
		n %= 3600;
	}

	if (n >= 60){
		b = n / 60;
		n %= 60;
	}

	if (a < 10)
		std::cout << 0 << a;
	else
		std::cout << a;

	std::cout << ":";

	if (b < 10)
		std::cout << 0 << b;
	else
		std::cout << b;

	std::cout << ":";

	if (n < 10)
		std::cout << 0 << n;
	else
		std::cout << n;

	return 0;
}

// 6 * 6 * 6 = 