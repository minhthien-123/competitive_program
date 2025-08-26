#include <bits/stdc++.h>
#define task "deldigit"
#define ll long long

const int maxn = 1e6 + 7;

std::string s;
int k, n, q;
int a[maxn];
std::stack<int> st;
std::vector<int> v;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> s;
    std::cin >> k;

    for (int i = 0; i < s.size(); i++)
        a[i] = s[i] - '0';
    n = s.size();
    q = 0;

    for (int i = 0; i < n; i++){
        while (!st.empty() && a[st.top()] < a[i] && q < k){
            st.pop();
            q++;
        }

        st.push(i);
    };

    //std::cout << q << " " << k << "\n";

    while (q < k){
        st.pop();
        q++;
    }

    while(!st.empty()){
        v.push_back(a[st.top()]);
        st.pop();
    }

    for (int i = v.size() - 1; i >= 0; i--)
        std::cout << v[i];

    return 0;
}

// 9856
