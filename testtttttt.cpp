#include <bits/stdc++.h>
using namespace std;
int n,cnt,res;
vector<pair<int,int>> point;
int main() { ///meeting
    cin>>n;
    for (int i = 1; i <= n; i++) {
        int in,out; ///Thoi gian den, di cua 1 nguoi
        cin>>in>>out;
        point.push_back({in,0});
        point.push_back({out,1});
    }
    sort(point.begin(),point.end());

    for (int i = 0; i < point.size(); i++)
        std::cout << point[i].first << " " << point[i].second << "\n";

    for (int i = 0; i < point.size(); i++) { ///sweep line
        if(point[i].second == 0)
            res=max(res,++cnt);
        else
            cnt--;
    }
    cout<<res;
}
