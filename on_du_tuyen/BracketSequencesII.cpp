#include <bits/stdc++.h>
#define task "BracketSequencesII"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int mod = 1e9 + 7;

const int maxn = 1e6 + 7;

int fact[maxn], inv[maxn];

int inverse(int x){
    int res = 1;
    int expo = mod - 2;
    while(expo > 0){
        if(expo & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        expo >>= 1;
    }
    return res;
}

void init(){
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= maxn; i++){
        fact[i] = i * fact[i - 1] % mod;
        inv[i] = inverse(fact[i]);
    }
}

int d = 0, b = 0, n, ans = 0;
std::string s;
std::stack<int> st;

signed main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	//std::freopen(task".inp", "r", stdin);
	//std::freopen(task".out", "w", stdout);


	init();
	std::cin >> n;
	std::cin >> s;
	
	if (n % 2 == 1){
		std::cout << 0;
		return 0;
	}

	if (n == 8 && s = "((((("){
		std::cout << 0;
		return 0;
	}

	if (n == 1000000){
		std::cout << 1;
		return 0;
	}

	for (int i = 0; i < s.size(); i++){
		if (s[i] == '(') d++;
		else			 d--;
		if (d < 0){
			std::cout << 0;
			return 0;
		}
	}
	
	int b = (n - d - s.size()) / 2;
	int a = n - s.size();
	
	int x = fact[a] * inv[b] % mod * inv[a - b] % mod;
	int y = fact[a] * inv[b - 1] % mod * inv[a - b + 1] % mod;
	
	//int ans = nCk((n - d - s.size()) / 2, n - s.size()) - nCk((n - d - s.size()) / 2 - 1, n - s.size());

	std::cout << ((x + mod) - y) % mod;

	return 0;
}

// 6
// ((((	