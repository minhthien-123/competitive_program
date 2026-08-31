#include <bits/stdc++.h>
using namespace std;


int n, i, j;
bool flag = true;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("parentheses.inp", "r", stdin);
    freopen("parentheses.out", "w", stdout);

    cin >> n;
    for (j = 0; j < n; j++){
        string st;
        stack<char> s;
        bool flag = true;

        cin >> st;
        for (i = 0; i < st.size(); i++){
            if (st[i] == '(' || st[i] == '[' || st[i] == '{')
                s.push(st[i]);
            else{
                if (s.empty()) flag = false;
                else{
                    if      (s.top() == '(' && st[i] == ')') s.pop();
                    else if (s.top() == '[' && st[i] == ']') s.pop();
                    else if (s.top() == '{' && st[i] == '}') s.pop();
                    else     flag = false;
                }
            }
        }

        if (!s.empty()) flag = false;

        if (flag == false) cout << "NO\n";
        else               cout << "YES\n";

        //flag = true;
    }
}
