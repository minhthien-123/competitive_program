#include <bits/stdc++.h>

std::string st;
std::stack<int> s;
int beg, en, ans = INT_MIN;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("lbracket.inp", "r", stdin);
    std::freopen("lbracket.out", "w", stdout);

    getline(std::cin, st);

    for (int i = 0; i < st.size(); i++){
        if (st[i] == '(') s.push(i);
        else{
            if (!s.empty()) s.pop();
            if (s.size() > 0){
                if (i - s.top() > ans){
                    ans = i - s.top();
                    beg = s.top() + 2;
                    en  = i + 1;
                }
            }
            else s.push(i);
        }
    }

    std::cout << ans << "\n";
    std::cout << beg << " " << en;

    return 0;
}