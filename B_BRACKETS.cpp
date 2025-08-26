#include <bits/stdc++.h>
using namespace std;

struct br{
    char val;
    int dex;
};

stack <char> s;
string       str;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin << str){
        for (int i = 0; i <= str.size(); i++){
            if (str[i] == "("){
                s.push("(")
            }
        }
    }

    return 0;
}
