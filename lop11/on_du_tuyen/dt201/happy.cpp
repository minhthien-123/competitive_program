#include <bits/stdc++.h>
#define task "happy"
#define int long long

int n, ans = 0;
std::string s;
int a[1000005];
std::vector<std::pair<char, char>> v;

char out(int x){
    if (x == 0)
        return 'A';
    else if (x == 1)
        return 'B';
    else
        return 'C';
}

void solve(int x, int row){
    if (x == -1) return;
    if (a[x] == row){
        solve(x - 1, row);
    }
    else{
        solve(x - 1, 3 - row - a[x]);
        v.push_back({out(a[x]), out(row)});
        a[x] = row;
        solve(x - 1, row);
    }
}

main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("happy.inp", "r", stdin);
    std::freopen("happy.out", "w", stdout);

    std::cin >> n;
    std::cin >> s;

    for (int i = 0; i < n; i++){
        if (s[i] == 'B')
            a[i] = 1;
        else if (s[i] == 'C')
            a[i] = 2;
        else
            a[i] = 0;
    }

    for (int i = 0; i < n; i++){
        if (s[i] == 'B')
            a[i] = 1;
        else if (s[i] == 'C')
            a[i] = 2;
        else
            a[i] = 0;
    }
    solve(n - 1, 2);

    std::cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i].first << v[i].second << "\n";

    return 0;
}
