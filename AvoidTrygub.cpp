#include <bits/stdc++.h>
#define task "AvoidTrygub"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

int t;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::freopen(task".inp", "r", stdin);
	std::freopen(task".out", "w", stdout);

	std::cin >> t;
	while (t--){
		int n;
		std::string s;
		std::cin >> n >> s;
		std::sort(s.begin(), s.end());
		std::cout << s << "\n";
	}

	return 0;
}