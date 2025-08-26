#include <bits/stdc++.h>
using namespace std;

string st;
stack<int> s;
int i, ans = INT_MIN, beg, en;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("lbracket.inp", "r", stdin);
    //freopen("lbracket.out", "w", stdout);

    cin >> st;
    s.push(-1);

    for (i = 0; i < st.size(); i++){
        if (st[i] == '(') s.push(i);
        else{
            s.pop();
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

    cout << ans << "\n";
    cout << beg << " " << en;
}
