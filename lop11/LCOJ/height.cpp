#include <bits/stdc++.h>
using namespace std;

struct height
{
    /* data */
    long long height;
    long long index;
    long long ans;
};

bool ss(height x, height y){
    return x.height < y.height;
}

long long i, n;
height heights[1000005];

int main(){
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> heights[i].height;
        heights[i].index=i;
    }

    sort(heights, heights + n, ss);

    //for (i = 0; i < n; i++)
    //    cout << heights[i].height << " "; // << heights[i].index << "\n";

    for(i = 0; i < n; i++){
        if (heights[i].height == heights[i - 1].height){
            //cout << i << " ";
            heights[heights[i].index].ans = heights[heights[i - 1].index].ans;
        }
        else
            heights[heights[i].index].ans = i;
    }

    //cout << "\n";

    for (i = 0; i < n; i++)
        cout << heights[i].ans << " ";
    return 0;
}
