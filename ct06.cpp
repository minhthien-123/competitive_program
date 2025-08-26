#include <bits/stdc++.h>

#define ll long long

struct arr
{
    ll dex;
    ll type;
};

bool ss(arr x, arr y){
    if (x.type == y.type) return x.dex < y.dex;
    else return x.type < y.type;
}

ll n;
arr a[1000005];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("ct06.inp", "r", stdin);
    std::freopen("ct06.out", "w", stdout);

    std::cin >> n;

    for (ll i = 0; i < n; i++)
        std::cin >> a[i].dex >> a[i].type;

    std::sort(a, a + n, ss);

    for (ll i = 0; i < n; i++){
        std::cout << a[i].dex << " " << a[i].type << "\n";
    }

    return 0;
}