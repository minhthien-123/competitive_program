#include <iostream>
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int n;
ll x = 0;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;
	while (n--){
		ll tmp;
		std::cin >> tmp;
		x ^= tmp;
	}

	std::cout << x;

	return 0;
}